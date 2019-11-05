#include "Hooks.h"
#include "Application.h"

void __fastcall Hooks::PlayerDoFrameHook(Player* PlayerPtr)
{
    static int OnLoadCounter = 0;
    static int TimesCalled = 0;
    static bool InitEventTriggered = false;
    if (!InitEventTriggered)
    {
        if (TimesCalled >= 200) //Wait 200 frames to ensure everything is initialized
        {
            Globals::Scripts->TriggerInitializedEvent();
            InitEventTriggered = true;
        }
        else
        {
            TimesCalled++;
        }
    }
    if (Globals::CanTriggerOnLoadEvent)
    {
        if (OnLoadCounter >= 200) //Wait 200 frames to ensure everything is initialized
        {
            Globals::Scripts->TriggerLoadEvent();
            Globals::CanTriggerOnLoadEvent = false;
            OnLoadCounter = 0;
        }
        else
        {
            OnLoadCounter++;
        }
    }

    if (Globals::PlayerPtr != PlayerPtr)
    {
        Globals::PlayerPtr = PlayerPtr;
        Globals::PlayerRigidBody = rfg::HavokBodyGetPointer(PlayerPtr->HavokHandle);
        if (Globals::Scripts)
        {
            Globals::Scripts->UpdateRfgPointers();
        }
    }

    if (!Globals::Gui)
    {
        return rfg::PlayerDoFrame(PlayerPtr);
    }
    static GuiReference<GeneralTweaksGui> TweaksMenuRef = Globals::Gui->GetGuiReference<GeneralTweaksGui>("General tweaks").value();
    static GuiReference<FreeCamGui> FreeCamMenuRef = Globals::Gui->GetGuiReference<FreeCamGui>("Camera settings").value();

    if (!Globals::Camera)
    {
        return rfg::PlayerDoFrame(PlayerPtr);
    }

    if (Globals::InfiniteJetpack)
    {
        PlayerPtr->JetpackFuelPercent = 1.0f;
    }
    if (TweaksMenuRef.Get().Invulnerable || (Globals::Camera->IsFreeCameraActive() && FreeCamMenuRef.Get().PlayerFollowCam))
    {
        PlayerPtr->Flags.invulnerable = true;
        PlayerPtr->HitPoints = 2147483647.0f;
    }
    if (Globals::Camera->IsFreeCameraActive())
    {
        PlayerPtr->Flags.ai_ignore = true;
    }
    if (TweaksMenuRef.Get().NeedCustomJumpHeightSet)
    {
        PlayerPtr->CodeDrivenJumpHeight = TweaksMenuRef.Get().CustomJumpHeight;
    }
    if (TweaksMenuRef.Get().LockAlertLevel)
    {
        rfg::GsmSetAlertLevel(TweaksMenuRef.Get().CustomAlertLevel);
    }

    if (Globals::Camera->IsFreeCameraActive() && FreeCamMenuRef.Get().PlayerFollowCam)
    {
        Globals::Camera->UpdateFreeView();
        vector CameraPos(*Globals::Camera->RealX, *Globals::Camera->RealY + 1.5f, *Globals::Camera->RealZ);
        rfg::HumanTeleportUnsafe(PlayerPtr, CameraPos, PlayerPtr->Orientation);
    }
    if (!Globals::Camera->IsFreeCameraActive() && Globals::Camera->NeedPostDeactivationCleanup)
    {
        if (FreeCamMenuRef.Get().ReturnPlayerToOriginalPosition)
        {
            rfg::HumanTeleportUnsafe(PlayerPtr, Globals::Camera->OriginalCameraPosition, PlayerPtr->Orientation);
        }
        Globals::Camera->NeedPostDeactivationCleanup = false;
    }

    if (Globals::Camera)
    {
        if (Globals::Camera->IsFirstPersonCameraActive())
        {
            if (Globals::Camera->UseThirdPersonForVehicles)
            {
                if (PlayerPtr->VehicleHandle != 0xFFFFFFFF)
                {
                    Globals::Camera->PauseFirstPersonCamera();
                }
                else
                {
                    Globals::Camera->UnpauseFirstPersonCamera();
                    Globals::Camera->UpdateFirstPersonView();
                }
            }
            else
            {
                if (Globals::Camera->IsFirstPersonCameraPaused())
                {
                    Globals::Camera->UnpauseFirstPersonCamera();
                }
                Globals::Camera->UpdateFirstPersonView();
            }
        }
    }

    //Todo: Make some kind of event system/class to avoid needing to do this and having tons of globals laying around
    //This is done to avoid problems when a thread spawned by the RSL tries teleporting the player at an unsafe time for doing so.
    if (Globals::PlayerNeedsTeleport)
    {
        rfg::HumanTeleportUnsafe(PlayerPtr, Globals::PlayerTeleportPos, PlayerPtr->Orientation);
        Globals::PlayerNeedsTeleport = false;
    }

    return rfg::PlayerDoFrame(PlayerPtr);
}

void __cdecl Hooks::HookDoFrameHook()
{
    Globals::HookDidFrame = true;
    return rfg::HookDoFrame();
}
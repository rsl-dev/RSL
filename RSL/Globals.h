#pragma once
#include "Includes.h"
#include "FixedArrayWrapper.h"
#include "RFGR_Types_Movers.h"
#include "Version.h"
#include "BuildDate.h"
#include <magic_enum/magic_enum.hpp>
#include <Hypodermic/Hypodermic.h>

//Todo: Move as many of these as possible into classes instead of having them be global

/*RSL*/
#define USE_LAUNCHER true
#define LOG_CF_OPEN_CALLS false //If true logs calls to cf_open via it's hook. This function is called for a majority of the games files so it's disabled by default for performance.
#define LUA_ENABLED true

//using json = nlohmann::json;
namespace fs = std::filesystem;
using uint = unsigned int;
using ulong = unsigned long;
using ulonglong = unsigned long long;
using string = std::string;

class Application;
class GuiSystem;
class ScriptManager;
class RenderInterfaceD3D11;
class GraphicsStateWrapper;

extern std::shared_ptr<Hypodermic::Container> IocContainer;

namespace Globals
{
    extern uint ExitKeysPressCount;
    
	extern Player* PlayerPtr;
	extern World* RfgWorldPtr;
	extern rl_light* TODLightPtr;
	extern rl_camera* RlCameraPtr;
	extern rl_renderer* RlRendererPtr;
	extern rl_render_lib* RlRenderLibPtr;
	extern rl_state_manager* RlStateManagerPtr;
	extern rl_scene* MainScenePtr;
	extern rl_scene_renderer* MainSceneRendererPtr;
	extern rl_camera* MainSceneCameraPtr;
	extern hkpWorld* hkpWorldPtr;
	extern lua_State* RfgVintLuaState;
	extern hkpRigidBody* PlayerRigidBody;
    extern keen::GraphicsSystem* KeenGraphicsSystemPtr;
    extern stream_grid* MainStreamGrid;
    extern GraphicsStateWrapper GraphicsState;

    extern keen::ImmediateRenderer* ImmediateRenderer;

    extern FixedArrayWrapper<explosion_info> ExplosionInfos;
    extern uint* NumExplosionInfos;

    extern FixedArrayWrapper<material_effect_info> MaterialEffectInfos; //.data:0226B6F0 rfg.exe:$19EB6F0 #0 <Effect_infos>
    extern uint* NumMaterialEffectInfos; //.data:0226E4C4 rfg.exe:$19EE4C4 #0 <Num_effect_infos>

    extern FixedArrayWrapper<effect_info> EffectInfos; //.data:02602E60 rfg.exe:$1D82E60 #0 <Effect_info>
    extern uint* NumEffectInfos; //.data:02602DF0 rfg.exe:$1D82DF0 #0 <Num_effect_types>

    extern rfg::farray<vehicle_info, 163>* VehicleInfos; //.data:012FA5F8 rfg.exe:$12BA5F8 #12B8FF8 <Vehicle_info_pool>

    extern FixedArrayWrapper<int> ShadowMapSizes; //.rdata:01A81BB4 rfg.exe:$EC1BB4 #EC07B4 <shadow_map_resolutions> int[4]

	extern DWORD MouseGenericPollMouseVisible;
	extern DWORD CenterMouseCursorCall;

	extern const ImVec4 ColorTransparent;
	extern const ImVec4 ColorRed;
	extern const ImVec4 ColorGreen;
	extern const ImVec4 ColorBlue;
	extern const ImVec4 ColorBlack;
	extern const ImVec4 ColorWhite;
	extern const ImVec4 ColorPurple;
	extern const ImVec4 ColorOrange;
	extern const ImVec4 ColorYellow;

	extern const ImVec4 SecondaryTextColor;
	extern const ImVec4 ColorBlue2;

	extern const float pi;

	extern HMODULE ScriptLoaderModule;
	extern uintptr_t ModuleBase;
	extern DWORD PID;

	extern ImFont* FontNormal;
	extern ImFont* FontBig;
	extern ImFont* FontLarge;
	extern ImFont* FontHuge; 

	extern bool OpenDebugConsole;
    extern bool DumpTexturesWhenLoading;
    extern bool DisableNumpadWhileOverlayVisible;
	extern nlohmann::json MainConfig;
	extern float DefaultFreeCameraSpeed;
	extern float DefaultRotationSpeed;

	extern IDXGISwapChain* D3D11SwapchainPtr;
	extern ID3D11Device* D3D11Device;
	extern ID3D11DeviceContext* D3D11Context;
	extern ID3D11RenderTargetView* MainRenderTargetView;
	extern HWND GameWindowHandle;
	extern RECT WindowRect;
    extern keen::GraphicsSystem* GraphicsSystemPtr;
    
    extern matrix44 vpMatrix;

	extern bool ShowMainOverlay;

	extern float OverlayFontSize;
	extern bool show_demo_window;
	extern bool ImGuiInitialized;
	extern ImGuiIO io;
	extern bool OverlayActive;
	extern WNDPROC OriginalWndProc;
	extern bool FirstPersonModeActive;

	extern float GlobalExplosionStrengthMultiplier;
	extern bool UseGlobalExplosionStrengthMultiplier;
	extern bool UseExplosionRadiusLimits;
	extern float MinimumExplosionRadius;
	extern float MaximumExplosionRadius;

	extern bool InfiniteJetpack;

	extern HANDLE ConsoleHandle;
	extern bool* InMultiplayer;
	extern bool HookDidFrame;

	extern const WORD ConsoleMessageLabelTextAttributes;
	extern const WORD ConsoleMessageTextAttributes;
	extern const WORD ConsoleWarningTextAttributes;
	extern const WORD ConsoleErrorTextAttributes;
	extern const WORD ConsoleFatalErrorTextAttributes;
	extern const WORD ConsoleSuccessTextAttributes;
	extern const WORD ConsoleDefaultTextAttributes;

	extern bool BlockNextTildeInput;
	extern bool ScriptLoaderCloseRequested;

	extern bool HudVisible;
	extern bool FogVisible;

    extern bool ReadyForImGuiInit;

    extern bool* UnlimitedAmmo;
    extern bool* UnlimitedMagazineAmmo;
    extern bool* UnlimitedAiThrownWeapons;
    extern float* VehicleMaxSpeed;
    extern bool* SsaoVisionEnabled;
    extern int* RfgMaxCharges;
    extern bool* TodEnabled;
    //Note: TodOverride seems to really be something like "MaxTodValue", gotta be careful writing to it. Only use Globals::SetFloat, since it's apparently write protected by default.
    //extern float* TodOverride; //.rdata:01AAEB60 rfg.exe:$EEEB60 #EED760 <__real@41c00000>
    extern float* CurrentTimeOfDay; //.data:01E1CC80 rfg.exe:$125CC80 #125B680 <Current_time_of_day>

    extern bool LockoutModeEnabled;

    extern int* ChargeExplosionDelay; //.data:015D4728 rfg.exe:$1294728 #1293128 <RFG_charge_delay>

    extern rfg::farray<ui_menu*, 8>* RfgMenusList; //farray<ui_menu *,8> RfgMenusList //.data:015A7698 rfg.exe:$1267698 #1266098 <RfgMenusList>

    extern bool DisableDebrisDeletion;
    extern bool FindGmOverride;
    extern bool UseFindGmOverride;

    extern FixedArrayWrapper<weapon_info> WeaponInfos; //.data:037C2C9C rfg.exe:$3482C9C #0 <Weapon_infos>
    extern uint* NumWeaponInfos; //.data:037C2C94 rfg.exe:$3482C94 #0 <Num_weapon_infos>

	extern FixedArrayWrapper<item_info> ItemInfos; //.data:03C0F148 rfg.exe:$2C2F148 #0 <Item_infos>
	extern int* NumItemInfos; //.data:03BF7C5C rfg.exe:$2C17C5C #0 <Num_item_infos>
	extern int* MaxItemInfos; //.data:03C0F144 rfg.exe:$2C2F144 #0 <Max_item_infos>

    extern float* SpeedScale;
    extern float* Frametime; //.data:022B9560 rfg.exe:$1119560 #1117F60 <Frametime>
    extern float* PlayerMaxMovementSpeedOverride; //.data:03DCF0B4 rfg.exe:$2C2F0B4 #0 <Player_max_movement_speed_override>

    extern bool CanTriggerOnLoadEvent;

    extern bool ForceVehicleDrops;

    extern vehicle_spawn_params VehicleSpawnCache;

    extern bool PlayerNeedsTeleport;
    extern vector PlayerTeleportPos;

    namespace Launcher
    {
        extern bool ShouldRunRsl; //Used by the launcher WndProc to track if the launcher should launch the main RSL code after it closes or start a vanilla game.
        extern bool LauncherRan;
    }
    
	const char* GetScriptLoaderVersion();
	bool DirectoryExists(const std::string& Directory);
	void CreateDirectoryIfNull(const std::string& Directory);
	float FloatConvertDegreesToRadians(float AngleInDegrees);
	float FloatConvertRadiansToDegrees(float AngleInRadians);
	float sind(float AngleInDegrees);
	float cosd(float AngleInDegrees);
	float tand(float AngleInDegrees);
	void SetConsoleAttributes(WORD Attributes);
	void ResetConsoleAttributes();
	HWND FindTopWindow(DWORD pid);
	HWND FindRfgTopWindow();
	DWORD GetProcessID(const std::string& ProcessName);
	void EnforceFloatRange(float& Value, float& Minimum, float& Maximum);
	void ChangeMemoryFloat(DWORD BaseAddress, float Value, DWORD Offset1, DWORD Offset2, bool PrintMessage);
	std::string GetEXEPath(bool IncludeExeInPath = false);
	void PlaceNOP(BYTE* Address, DWORD Length = 1);
    void SetFloat(float* Address, float NewValue);
    void EnableMemoryRegionReadWrite(void* RegionAddress, ulong RegionSize);
	MODULEINFO GetModuleInfo(const char* ModuleName);
	DWORD FindPattern(const char* ModuleName, const char* PatternString, const char* MaskString);
    std::string CharArrayToString(char* Array, int Size);
    std::string CharArrayToString(const char* Array, int Size);

    void TryHideInvalidMainMenuOptions();
    void LogGameMenuInfo();

    std::string GetLastWin32ErrorAsString();

    std::string RemoveFileExtension(const std::string& Filename);
    std::array<std::string, 2> SplitFilename(const std::string& Filename);

    std::optional<explosion_info*> GetExplosionInfo(std::string Name);

	template <typename T>
	std::string to_string_precise(const T Value, const int Precision = 1)
	{
		std::ostringstream Out;
		Out.precision(Precision);
		Out << std::fixed << Value;
		return Out.str();
	}

    extern std::vector<HANDLE> RfgThreadHandles;
    extern void SuspendAllThreadsExceptLauncher(HANDLE LauncherThreadHandle);
    extern void ResumeAllThreads();
}

template<class T>
T OffsetPtr(unsigned long Offset)
{
    if(Globals::ModuleBase == 0)
    {
        Globals::ModuleBase = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
    }
    return reinterpret_cast<T>(Globals::ModuleBase + Offset);
}

class KeyState
{
public:
    bool ControlDown = false;
    bool ShiftDown = false;
    bool AltDown = false;
    bool WindowsDown = false;
};
#include "Hooks.h"

void __fastcall Hooks::ApplicationUpdateTimeHook(void* This, void* edx, float TimeStep)
{
    return rfg::ApplicationUpdateTime(This, edx, TimeStep);
}
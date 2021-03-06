#pragma once
/*RSL*/

#define SCRIPT_LOADER_DLL //Used along with ifdef in injector files to make sure ./Injector/Globals.hpp is never accidentally included.

#define NOIME

#include <sstream>
//Target windows 7 with win10 sdk
#include <winsdkver.h>
#define _WIN32_WINNT 0x0601
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <windowsx.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
#include <tuple>
#include <locale>

#include <cctype>
#include <cmath>
#include <random>

#include <chrono>
#include <iostream>
#include <tlhelp32.h>
#include <Psapi.h>

#include <ShellScalingAPI.h>
#include <wrl.h>
#include <d3d11_1.h>
#include <DXGI.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <filesystem>
#include <nlohmann/json.hpp>

#include <kiero/kiero.h>
#include <MinHook/MinHook.h>

#define IMGUI_IMPL_WIN32_DISABLE_LINKING_XINPUT 
#define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
#include <imgui.h>
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <IconsFontAwesome5.h>
#include "imgui_stdlib.h"

#include <tchar.h>
#include <thread>
#include <mutex>
#include <windef.h>

#define SOL_CHECK_ARGUMENTS 1
#include <sol.hpp>

#define FMT_HEADER_ONLY 1
#include <fmt/core.h>
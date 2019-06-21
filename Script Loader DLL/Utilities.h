#pragma once
#include "RenderInterfaceD3D11.h"

namespace Utilities::Json
{
	void SetFloat4(nlohmann::json& Json, const char* FirstKey, const char* SecondKey, float r, float g, float b, float a);
	void SetFloat4(nlohmann::json& Json, const char* FirstKey, const char* SecondKey, ImVec4 Color);
	ImVec2 GetFloat2(nlohmann::json& Json, const char* FirstKey, const char* SecondKey);
	ImVec4 GetFloat4(nlohmann::json& Json, const char* FirstKey, const char* SecondKey);
}

namespace Utilities::GUI
{
	void TooltipOnPrevious(std::string& Description, ImFont* Font = nullptr);
	void TooltipOnPrevious(const char* Description, ImFont* Font = nullptr);
	void ShowHelpMarker(const char* Description);
    void LabelAndValue(std::string Label, std::string Value);
}

namespace Utilities::General
{
    void ThreadedBeep(ulong Frequency, ulong Duration);
}
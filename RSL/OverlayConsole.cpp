#include "OverlayConsole.h"

OverlayConsole::OverlayConsole(std::string Title_)
{
	Title = Title_;
	WindowFlags = 0;
	WindowFlags |= ImGuiWindowFlags_NoTitleBar;
	WindowFlags |= ImGuiWindowFlags_NoMove;
	WindowFlags |= ImGuiWindowFlags_NoCollapse;
	
    ScriptManager = IocContainer->resolve<IScriptManager>();
}

void OverlayConsole::Draw()
{
	if (!Visible)
        return;

    ImGui::SetNextWindowSizeConstraints(ImVec2(-1, 0), ImVec2(-1, FLT_MAX));
	ImGui::SetNextWindowSize(ImVec2(static_cast<float>(Globals::WindowRect.right - Globals::WindowRect.left), 200.0f), ImGuiCond_Once);
	ImGui::SetNextWindowPos(ImVec2(0.0f, Globals::OverlayActive ? 22.0f : 0.0f)); //FontSize + 5.0f seems to work for menu bar alignment.
	if (!ImGui::Begin(Title.c_str(), &Visible, WindowFlags))
	{
		ImGui::End();
		return;
	}

	ImVec4* Colors = ImGui::GetStyle().Colors; //48 items
	ImGui::PushStyleColor(ImGuiCol_ResizeGrip, Colors[ImGuiCol_WindowBg]);
	ImGui::PushStyleColor(ImGuiCol_ResizeGripHovered, Colors[ImGuiCol_WindowBg]);
	ImGui::PushStyleColor(ImGuiCol_ResizeGripActive, Colors[ImGuiCol_WindowBg]);
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4.0f, 2.0f));
	const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text
	ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText

	int BufferCount = 0;
	int i = BufferDisplayLength - 1;
	if (i >= Logger::LogCache.size())
        i = Logger::LogCache.size() - 1;

    while (i >= 0 && BufferCount < BufferDisplayLength)
	{
		if (!(Logger::LogCache[i].Flags & ConsoleLogType))
		{
			i--;
			continue;
		}

        if (Logger::LogCache[i].Flags & LogNone || SimpleOutput)
            ImGui::TextUnformatted(Logger::LogCache[i].Message.c_str());
        else
        {
            ImGui::TextUnformatted("[");
            ImGui::SameLine();
            if (Logger::LogCache[i].Flags & LogInfo)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.945f, 0.945f, 0.945f, 1.0f));
                ImGui::TextUnformatted("Info");
                ImGui::PopStyleColor();
            }
            else if (Logger::LogCache[i].Flags & LogWarning)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.756f, 0.611f, 0.000f, 1.0f));
                ImGui::TextUnformatted("Warning");
                ImGui::PopStyleColor();
            }
            else if (Logger::LogCache[i].Flags & LogLua)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.231f, 0.470f, 1.000f, 1.0f));
                ImGui::TextUnformatted("Lua");
                ImGui::PopStyleColor();
            }
            else if (Logger::LogCache[i].Flags & LogJson)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.000f, 0.415f, 0.000f, 1.0f));
                ImGui::TextUnformatted("Json");
                ImGui::PopStyleColor();
            }
            else if (Logger::LogCache[i].Flags & LogError)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.772f, 0.058f, 0.121f, 1.0f));
                ImGui::TextUnformatted("Error");
                ImGui::PopStyleColor();
            }
            else if (Logger::LogCache[i].Flags & LogFatalError)
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.772f, 0.058f, 0.121f, 1.0f));
                ImGui::TextUnformatted("Fatal Error");
                ImGui::PopStyleColor();
            }
            else
            {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.000f, 0.000f, 0.000f, 1.0f));
                ImGui::TextUnformatted("Undefined Message Type");
                ImGui::PopStyleColor();
            }
            ImGui::SameLine();
            ImGui::TextUnformatted("] ");
            ImGui::SameLine();
            ImGui::TextUnformatted(Logger::LogCache[i].Message.c_str());
        }
        BufferCount++;

        i--;
	}
	BufferCount = 0;

	//Auto-scrolls console output to bottom unless the user scrolls up.
	if (Autoscroll)
        ImGui::SetScrollHereY(1.0f);

    ImGui::EndChild();
	ImGui::PopStyleVar();

	/*moneyl: Full credit goes to Elias Daler for the use of a stateless lambda and wrapper to pass a callback lambda to the InputText widget. I was having trouble implementing this, and his
	article here gave a solution: https://eliasdaler.github.io/using-imgui-with-sfml-pt2/ This method is preferred to having a separate callback function since it keeps the code in one place,
	and cleaner. He also described a general method of doing this for any widget which may be useful later on. Keep this in mind for future gui additions which might use it.*/
	if (InputTextLambdaWrapper("##LuaConsoleInput", &InputBuffer, ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackHistory, 
    [&](ImGuiInputTextCallbackData* CallbackData)
	{
		//Callback lambda which handles up/down key presses
		if (CallbackData->EventFlag == ImGuiInputTextFlags_CallbackHistory)
		{
			if (CallbackData->EventKey == ImGuiKey_UpArrow)
			{
				if (HistoryPosition > 0)
                    HistoryPosition--;
                if (HistoryPosition < CommandHistory.size())
                {
                    CallbackData->DeleteChars(0, CallbackData->BufTextLen);
                    CallbackData->InsertChars(0, CommandHistory[HistoryPosition].c_str());
                }
			}
			else if (CallbackData->EventKey == ImGuiKey_DownArrow)
			{
				if (HistoryPosition < CommandHistory.size() - 1)
                    HistoryPosition++;
                if(HistoryPosition < CommandHistory.size())
                {
                    CallbackData->DeleteChars(0, CallbackData->BufTextLen);
                    CallbackData->InsertChars(0, CommandHistory[HistoryPosition].c_str());
                }
			}
		}
		return 0;
	}))
	{
		//This executes when the if statement returns true -> if the enter key is pressed.
		CommandHistory.push_back(InputBuffer);
        Logger::LogLua("{}\n", InputBuffer);
		HistoryPosition = CommandHistory.size(); //Since pressing the up arrow key will subtract by one, the subtraction by one is not done here to insure the latest history entry isn't skipped.
        ScriptManager->RunScript(InputBuffer, "lua console command");
		InputBuffer.clear();
		ReclaimFocus = true;
	}
	ImGui::SameLine();
	ImGui::Checkbox("Auto scroll", &Autoscroll);
	ImGui::SameLine();
	ImGui::Checkbox("Simple output", &SimpleOutput);

	// Auto-focus on window apparition
	ImGui::SetItemDefaultFocus();
	if (ReclaimFocus)
	{
		ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget
		ReclaimFocus = false;
	}

	ImGui::PopStyleColor(3);
	ImGui::End();
}

template<typename T>
inline bool OverlayConsole::InputTextLambdaWrapper(const char* Label, std::string* Buffer, ImGuiInputTextFlags Flags, T Callback, void* UserData)
{
	auto FreeCallback = [](ImGuiTextEditCallbackData* Data)
	{
		auto& f = *static_cast<T*>(Data->UserData);
		return f(Data);
	};
	return ImGui::InputText(Label, Buffer, Flags, FreeCallback, &Callback);
}
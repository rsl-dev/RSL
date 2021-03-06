#pragma once
#include "Bootstrapper.h"

class Application
{
public:
    Application();
    ~Application() = default;

    void Run();

private:
    void MainLoop();
    void Exit();

    [[nodiscard]] bool IsDisabledGameState(GameState State) const;
    [[nodiscard]] bool ShouldClose() const;
    void OpenConsole();
    void CloseConsole() const;

    std::shared_ptr<IIpcManager> IpcManager = nullptr;
    std::shared_ptr<ISnippetManager> SnippetManager = nullptr;
    std::shared_ptr<ICameraManager> CameraManager = nullptr;
    std::shared_ptr<IHookManager> Hooks = nullptr;
    std::shared_ptr<IGuiManager> GuiManager = nullptr;
    Bootstrapper RslBootstrapper;

    bool AutorunScriptsRun = false;
    const std::vector<GameState> DisabledGameStates = {
                                GS_WRECKING_CREW_MAIN_MENU, GS_WRECKING_CREW_CHARACTER_SELECT,
                                GS_WRECKING_CREW_SCOREBOARD, GS_WC_INIT, GS_WC_SHUTDOWN,
                                GS_MULTIPLAYER_LIVE, GS_MULTIPLAYER_LIVE_FIND_SERVERS };
};

#include "plugin.hpp"
#include "ui/PeripheralHUDFlowCoordinator.hpp"

peripheral_hud::plugin::plugin() {
    custom_types::Register::AutoRegister();

    QuestUI::Init();
    QuestUI::Register::RegisterMainMenuModSettingsFlowCoordinator<PeripheralHUD::UI::PeripheralHUDFlowCoordinator*>(modInfo);

    getLogger().info("Installing PeripheralHUD hooks...");
    InstallHooks();
    getLogger().info("Installed PeripheralHUD hooks...");
}

void peripheral_hud::plugin::InstallHooks() {
    hooks::EnvironmentSceneSetup();
}

peripheral_hud::plugin* g_Plugin = nullptr;

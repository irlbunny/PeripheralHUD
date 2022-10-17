#include "ui/SettingsViewController.hpp"
#include "config.hpp"
#include "GlobalNamespace/BeatmapLevelSO.hpp"
#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/SimpleLevelStarter.hpp"

DEFINE_TYPE(PeripheralHUD::UI, SettingsViewController);

void PeripheralHUD::UI::SettingsViewController::DidActivate(
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    using namespace GlobalNamespace;
    using namespace UnityEngine;
    using namespace UnityEngine::UI;

    if (firstActivation) {
        GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        // PerformanceTestLevelButton
        QuestUI::BeatSaberUI::CreateUIButton(container->get_transform(), "Preview",
            []() {
                auto simpleLevelStarters = Resources::FindObjectsOfTypeAll<SimpleLevelStarter*>();
                for (auto& starter : simpleLevelStarters) {
                    if (starter->get_gameObject()->get_name() == "OldPerformanceTestLevelButton") {
                        starter->gameplayModifiers->enabledObstacleType = GameplayModifiers::EnabledObstacleType::NoObstacles;
                        starter->StartLevel();
                        break;
                    }
                }
            }
        );
        
        std::vector<StringW> categoryValues = { "Combo", "Score", "Multiplier" };
        QuestUI::BeatSaberUI::CreateDropdown(container->get_transform(), "Category", categoryValues[0], categoryValues,
            [this, categoryValues](std::string value) {
                SelectCategory(value);
            }
        );

        // We don't have BSML, this code is BAD. L.

        #pragma region Combo
        auto hideComboInWorldToggle = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Combo In-World", getPeripheralHUDConfig().HideWorldCombo.GetValue(), 
            [](bool value) {
                getPeripheralHUDConfig().HideWorldCombo.SetValue(value);
            }
        );
        hideComboInWorldToggleGameObject = hideComboInWorldToggle->get_transform()->get_parent()->get_gameObject();
        hideComboInWorldToggleGameObject->set_active(false);
        auto hideComboInCameraToggle = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Combo In-Camera", getPeripheralHUDConfig().HideCameraCombo.GetValue(), 
            [](bool value) {
                getPeripheralHUDConfig().HideCameraCombo.SetValue(value);
            }
        );
        hideComboInCameraToggleGameObject = hideComboInCameraToggle->get_transform()->get_parent()->get_gameObject();
        hideComboInCameraToggleGameObject->set_active(false);
        auto comboPositionXIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Combo Position X", 2, 5.f, getPeripheralHUDConfig().ComboPositionX.GetValue(), -1000, 1000,
            [](float value) {
                getPeripheralHUDConfig().ComboPositionX.SetValue(value);
            }
        );
        comboPositionXIncrementSettingGameObject = comboPositionXIncrementSetting->get_gameObject();
        comboPositionXIncrementSettingGameObject->set_active(false);
        auto comboPositionYIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Combo Position Y", 2, 5.f, getPeripheralHUDConfig().ComboPositionY.GetValue(), -1000, 1000,
            [](float value) {
                getPeripheralHUDConfig().ComboPositionY.SetValue(value);
            }
        );
        comboPositionYIncrementSettingGameObject = comboPositionYIncrementSetting->get_gameObject();
        comboPositionYIncrementSettingGameObject->set_active(false);
        auto comboScaleIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Combo Scale", 2, .05f, getPeripheralHUDConfig().ComboScale.GetValue(), 0, 10,
            [](float value) {
                getPeripheralHUDConfig().ComboScale.SetValue(value);
            }
        );
        comboScaleIncrementSettingGameObject = comboScaleIncrementSetting->get_gameObject();
        comboScaleIncrementSettingGameObject->set_active(false);
        #pragma endregion
        #pragma region Score
        auto hideScoreInWorldToggle = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Score In-World", getPeripheralHUDConfig().HideWorldScore.GetValue(), 
            [](bool value) {
                getPeripheralHUDConfig().HideWorldScore.SetValue(value);
            }
        );
        hideScoreInWorldToggleGameObject = hideScoreInWorldToggle->get_transform()->get_parent()->get_gameObject();
        hideScoreInWorldToggleGameObject->set_active(false);
        auto hideScoreInCameraToggle = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Score In-Camera", getPeripheralHUDConfig().HideCameraScore.GetValue(), 
            [](bool value) {
                getPeripheralHUDConfig().HideCameraScore.SetValue(value);
            }
        );
        hideScoreInCameraToggleGameObject = hideScoreInCameraToggle->get_transform()->get_parent()->get_gameObject();
        hideScoreInCameraToggleGameObject->set_active(false);
        auto scorePositionXIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Score Position X", 2, 5.f, getPeripheralHUDConfig().ScorePositionX.GetValue(), -1000, 1000,
            [](float value) {
                getPeripheralHUDConfig().ScorePositionX.SetValue(value);
            }
        );
        scorePositionXIncrementSettingGameObject = scorePositionXIncrementSetting->get_gameObject();
        scorePositionXIncrementSettingGameObject->set_active(false);
        auto scorePositionYIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Score Position Y", 2, 5.f, getPeripheralHUDConfig().ScorePositionY.GetValue(), -1000, 1000,
            [](float value) {
                getPeripheralHUDConfig().ScorePositionY.SetValue(value);
            }
        );
        scorePositionYIncrementSettingGameObject = scorePositionYIncrementSetting->get_gameObject();
        scorePositionYIncrementSettingGameObject->set_active(false);
        auto scoreScaleIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Score Scale", 2, .05f, getPeripheralHUDConfig().ScoreScale.GetValue(), 0, 10,
            [](float value) {
                getPeripheralHUDConfig().ScoreScale.SetValue(value);
            }
        );
        scoreScaleIncrementSettingGameObject = scoreScaleIncrementSetting->get_gameObject();
        scoreScaleIncrementSettingGameObject->set_active(false);
        #pragma endregion
        #pragma region Multiplier
        auto hideMultiplierInWorldToggle = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Multiplier In-World", getPeripheralHUDConfig().HideWorldMultiplier.GetValue(), 
            [](bool value) {
                getPeripheralHUDConfig().HideWorldMultiplier.SetValue(value);
            }
        );
        hideMultiplierInWorldToggleGameObject = hideMultiplierInWorldToggle->get_transform()->get_parent()->get_gameObject();
        hideMultiplierInWorldToggleGameObject->set_active(false);
        auto hideMultiplierInCameraToggle = QuestUI::BeatSaberUI::CreateToggle(container->get_transform(), "Hide Multiplier In-Camera", getPeripheralHUDConfig().HideCameraMultiplier.GetValue(), 
            [](bool value) {
                getPeripheralHUDConfig().HideCameraMultiplier.SetValue(value);
            }
        );
        hideMultiplierInCameraToggleGameObject = hideMultiplierInCameraToggle->get_transform()->get_parent()->get_gameObject();
        hideMultiplierInCameraToggleGameObject->set_active(false);
        auto multiplierPositionXIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Multiplier Position X", 2, 5.f, getPeripheralHUDConfig().MultiplierPositionX.GetValue(), -1000, 1000,
            [](float value) {
                getPeripheralHUDConfig().MultiplierPositionX.SetValue(value);
            }
        );
        multiplierPositionXIncrementSettingGameObject = multiplierPositionXIncrementSetting->get_gameObject();
        multiplierPositionXIncrementSettingGameObject->set_active(false);
        auto multiplierPositionYIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Multiplier Position Y", 2, 5.f, getPeripheralHUDConfig().MultiplierPositionY.GetValue(), -1000, 1000,
            [](float value) {
                getPeripheralHUDConfig().MultiplierPositionY.SetValue(value);
            }
        );
        multiplierPositionYIncrementSettingGameObject = multiplierPositionYIncrementSetting->get_gameObject();
        multiplierPositionYIncrementSettingGameObject->set_active(false);
        auto multiplierScaleIncrementSetting = QuestUI::BeatSaberUI::CreateIncrementSetting(container->get_transform(), "Multiplier Scale", 2, .05f, getPeripheralHUDConfig().MultiplierScale.GetValue(), 0, 10,
            [](float value) {
                getPeripheralHUDConfig().MultiplierScale.SetValue(value);
            }
        );
        multiplierScaleIncrementSettingGameObject = multiplierScaleIncrementSetting->get_gameObject();
        multiplierScaleIncrementSettingGameObject->set_active(false);
        #pragma endregion

        SelectCategory("Combo");
    }
}

void PeripheralHUD::UI::SettingsViewController::SelectCategory(std::string category) {
    bool isCombo = category == "Combo";
    bool isScore = category == "Score";
    bool isMultiplier = category == "Multiplier";

    // Combo
    hideComboInWorldToggleGameObject->set_active(isCombo);
    hideComboInCameraToggleGameObject->set_active(isCombo);
    comboPositionXIncrementSettingGameObject->set_active(isCombo);
    comboPositionYIncrementSettingGameObject->set_active(isCombo);
    comboScaleIncrementSettingGameObject->set_active(isCombo);

    // Score
    hideScoreInWorldToggleGameObject->set_active(isScore);
    hideScoreInCameraToggleGameObject->set_active(isScore);
    scorePositionXIncrementSettingGameObject->set_active(isScore);
    scorePositionYIncrementSettingGameObject->set_active(isScore);
    scoreScaleIncrementSettingGameObject->set_active(isScore);

    // Multiplier
    hideMultiplierInWorldToggleGameObject->set_active(isMultiplier);
    hideMultiplierInCameraToggleGameObject->set_active(isMultiplier);
    multiplierPositionXIncrementSettingGameObject->set_active(isMultiplier);
    multiplierPositionYIncrementSettingGameObject->set_active(isMultiplier);
    multiplierScaleIncrementSettingGameObject->set_active(isMultiplier);
}

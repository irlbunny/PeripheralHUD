#pragma once
#include "plugin.hpp"

DECLARE_CLASS_CODEGEN(PeripheralHUD::UI, SettingsViewController, HMUI::ViewController,
    // Combo
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, hideComboInWorldToggleGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, hideComboInCameraToggleGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, comboPositionXIncrementSettingGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, comboPositionYIncrementSettingGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, comboScaleIncrementSettingGameObject);

    // Score
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, hideScoreInWorldToggleGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, hideScoreInCameraToggleGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, scorePositionXIncrementSettingGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, scorePositionYIncrementSettingGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, scoreScaleIncrementSettingGameObject);

    // Multiplier
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, hideMultiplierInWorldToggleGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, hideMultiplierInCameraToggleGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, multiplierPositionXIncrementSettingGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, multiplierPositionYIncrementSettingGameObject);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, multiplierScaleIncrementSettingGameObject);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

public:
    void SelectCategory(std::string category);
)

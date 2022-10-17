#pragma once
#include "plugin.hpp"

DECLARE_CLASS_CODEGEN(PeripheralHUD::UI, PeripheralHUDViewController, HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(HMUI::FlowCoordinator*, flowCoordinator);

    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, settingsButton);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, aboutButton);
    
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

public:
    UnityEngine::UI::Button* CreateUIViewControllerButton(UnityEngine::Transform* parent, std::string title, std::string description, HMUI::ViewController* viewController);
)

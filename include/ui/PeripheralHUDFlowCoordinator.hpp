#pragma once
#include "plugin.hpp"
#include "ui/PeripheralHUDViewController.hpp"

DECLARE_CLASS_CODEGEN(PeripheralHUD::UI, PeripheralHUDFlowCoordinator, HMUI::FlowCoordinator,
    DECLARE_INSTANCE_FIELD(PeripheralHUD::UI::PeripheralHUDViewController*, peripheralHUDViewController);
    DECLARE_INSTANCE_FIELD(HMUI::ViewController*, currentViewController);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, BackButtonWasPressed, il2cpp_utils::FindMethodUnsafe("HMUI", "FlowCoordinator", "BackButtonWasPressed", 1), HMUI::ViewController* topViewController);
)

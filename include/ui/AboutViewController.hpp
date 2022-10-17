#pragma once
#include "plugin.hpp"

DECLARE_CLASS_CODEGEN(PeripheralHUD::UI, AboutViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
)

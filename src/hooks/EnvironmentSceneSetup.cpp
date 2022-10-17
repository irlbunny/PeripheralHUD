#include "plugin.hpp"
#include "custom/CustomHUDController.hpp"
#include "GlobalNamespace/EnvironmentSceneSetup.hpp"
#include "UnityEngine/WaitForEndOfFrame.hpp"

custom_types::Helpers::Coroutine DelayedStart(GlobalNamespace::EnvironmentSceneSetup* environmentSceneSetup) {
    using namespace System::Collections;
    using namespace UnityEngine;
    using namespace Zenject;

    co_yield reinterpret_cast<IEnumerator*>(CRASH_UNLESS(WaitForEndOfFrame::New_ctor()));

    DiContainer* container = environmentSceneSetup->get_Container();
    Transform* parentTransform = environmentSceneSetup->get_transform()->get_parent();
    if (parentTransform) {
        GameObject* parentGO = parentTransform->get_gameObject();
        if (parentGO->get_name() == "Environment") {
            GameObject* controllerGO = GameObject::New_ctor("CustomHUDController");
            PeripheralHUD::CustomHUDController* controller = controllerGO->AddComponent<PeripheralHUD::CustomHUDController*>();
            controller->Initialize(container, parentGO);
        }
    }
}

MAKE_HOOK_MATCH(
    EnvironmentSceneSetup_InstallBindings,
    &GlobalNamespace::EnvironmentSceneSetup::InstallBindings,
    void,
    GlobalNamespace::EnvironmentSceneSetup* self
) {
    EnvironmentSceneSetup_InstallBindings(self);

    self->StartCoroutine(custom_types::Helpers::CoroutineHelper::New(DelayedStart(self)));
}

void peripheral_hud::hooks::EnvironmentSceneSetup() {
    INSTALL_HOOK(getLogger(), EnvironmentSceneSetup_InstallBindings);
}

#include "ui/PeripheralHUDFlowCoordinator.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

DEFINE_TYPE(PeripheralHUD::UI, PeripheralHUDFlowCoordinator);

void PeripheralHUD::UI::PeripheralHUDFlowCoordinator::DidActivate(
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    using namespace HMUI;
    
    if (firstActivation) {
        SetTitle(ID, ViewController::AnimationType::Out);

        showBackButton = true;

        peripheralHUDViewController = QuestUI::BeatSaberUI::CreateViewController<PeripheralHUD::UI::PeripheralHUDViewController*>();
        peripheralHUDViewController->flowCoordinator = this;

        currentViewController = nullptr;

        ProvideInitialViewControllers(peripheralHUDViewController, nullptr, nullptr, nullptr, nullptr);
    }
}

void PeripheralHUD::UI::PeripheralHUDFlowCoordinator::BackButtonWasPressed(
    HMUI::ViewController* topViewController
) {
    using namespace GlobalNamespace;
    using namespace HMUI;
    using namespace UnityEngine;

    if (currentViewController) {
        SetTitle(ID, ViewController::AnimationType::In);
        ReplaceTopViewController(peripheralHUDViewController, this, this, nullptr, ViewController::AnimationType::Out, ViewController::AnimationDirection::Horizontal);

        currentViewController = nullptr;
    } else {
        parentFlowCoordinator->DismissFlowCoordinator(this, ViewController::AnimationDirection::Horizontal, nullptr, false);
    }
}

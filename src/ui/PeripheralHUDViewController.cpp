#include "ui/PeripheralHUDViewController.hpp"
#include "ui/PeripheralHUDFlowCoordinator.hpp"
#include "ui/AboutViewController.hpp"
#include "ui/SettingsViewController.hpp"
#include "config.hpp"
#include "questui/shared/CustomTypes/Components/Backgroundable.hpp"
#include "GlobalNamespace/OVRPlugin.hpp"
#include "GlobalNamespace/OVRPlugin_SystemHeadset.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "UnityEngine/Application.hpp"
#include "UnityEngine/RectOffset.hpp"
#include "UnityEngine/UI/ContentSizeFitter.hpp"

DEFINE_TYPE(PeripheralHUD::UI, PeripheralHUDViewController);

void PeripheralHUD::UI::PeripheralHUDViewController::DidActivate(
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    using namespace GlobalNamespace;
    using namespace HMUI;
    using namespace UnityEngine;
    using namespace UnityEngine::UI;

    if (firstActivation) {
        VerticalLayoutGroup* verticalLayoutGroup = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(get_transform());

        GameObject* scrollView = QuestUI::BeatSaberUI::CreateScrollView(verticalLayoutGroup->get_transform());
        LayoutElement* scrollViewLayoutElement = scrollView->GetComponentInParent<LayoutElement*>();
        scrollViewLayoutElement->set_preferredWidth(120);
        scrollViewLayoutElement->set_preferredHeight(65);

        settingsButton = CreateUIViewControllerButton(scrollView->get_transform(), "Settings", "Configure PeripheralHUD however you like, etc.", QuestUI::BeatSaberUI::CreateViewController<PeripheralHUD::UI::SettingsViewController*>());
        aboutButton = CreateUIViewControllerButton(scrollView->get_transform(), "About", "More information about this plugin!", QuestUI::BeatSaberUI::CreateViewController<PeripheralHUD::UI::AboutViewController*>());

        HorizontalLayoutGroup* horizontalLayoutGroup = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(verticalLayoutGroup->get_transform());
        horizontalLayoutGroup->set_padding(RectOffset::New_ctor(8, 0, -5, 5));

        QuestUI::BeatSaberUI::CreateText(horizontalLayoutGroup->get_transform(), "Made with <3 by Kaitlyn, commissioned by Inderix", Vector2::get_zero(), Vector2(4, 4));
        Button* donateButton = QuestUI::BeatSaberUI::CreateUIButton(horizontalLayoutGroup->get_transform(), "Donate",
            []() {
                Application::OpenURL("https://www.patreon.com/join/ItsKaitlyn03");
            }
        );
        QuestUI::BeatSaberUI::SetButtonTextSize(donateButton, 3);
    }
}

UnityEngine::UI::Button* PeripheralHUD::UI::PeripheralHUDViewController::CreateUIViewControllerButton(
    UnityEngine::Transform* parent,
    std::string title,
    std::string description,
    HMUI::ViewController* viewController
) {
    using namespace HMUI;
    using namespace UnityEngine;
    using namespace UnityEngine::UI;

    HorizontalLayoutGroup* horizontalLayoutGroup = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(parent);
    QuestUI::Backgroundable* horizontalLayoutGroupBackgroundable = horizontalLayoutGroup->GetComponent<QuestUI::Backgroundable*>();
    horizontalLayoutGroupBackgroundable->ApplyBackground("panel-top");
    horizontalLayoutGroupBackgroundable->GetComponentInChildren<ImageView*>()->skew = .18f;
    LayoutElement* horizontalLayoutGroupLayoutElement = horizontalLayoutGroup->GetComponent<LayoutElement*>();
    horizontalLayoutGroupLayoutElement->set_preferredWidth(100);
    horizontalLayoutGroupLayoutElement->set_preferredHeight(15);

    VerticalLayoutGroup* verticalLayoutGroup = QuestUI::BeatSaberUI::CreateVerticalLayoutGroup(horizontalLayoutGroup->get_transform());
    verticalLayoutGroup->set_spacing(-5);
    verticalLayoutGroup->set_padding(RectOffset::New_ctor(0, 0, 2, 0));
    LayoutElement* verticalLayoutGroupLayoutElement = verticalLayoutGroup->GetComponent<LayoutElement*>();
    verticalLayoutGroupLayoutElement->set_preferredWidth(65);

    QuestUI::BeatSaberUI::CreateText(verticalLayoutGroup->get_transform(), title, Vector2::get_zero())->set_fontSize(5);
    QuestUI::BeatSaberUI::CreateText(verticalLayoutGroup->get_transform(), description, Vector2::get_zero())->set_fontSize(3);

    Button* openButton = QuestUI::BeatSaberUI::CreateUIButton(horizontalLayoutGroup->get_transform(), ">", "PlayButton",
        [this, title, viewController]() {
            flowCoordinator->SetTitle(title, ViewController::AnimationType::In);
            flowCoordinator->ReplaceTopViewController(viewController, flowCoordinator, flowCoordinator, nullptr, ViewController::AnimationType::In, ViewController::AnimationDirection::Horizontal);

            reinterpret_cast<PeripheralHUD::UI::PeripheralHUDFlowCoordinator*>(flowCoordinator)->currentViewController = viewController;
        }
    );
    QuestUI::BeatSaberUI::SetButtonTextSize(openButton, 5);

    Object::Destroy(openButton->get_transform()->Find("Content")->GetComponent<LayoutElement*>());

    ContentSizeFitter* contentSizeFitter = openButton->get_gameObject()->AddComponent<ContentSizeFitter*>();
    contentSizeFitter->set_horizontalFit(ContentSizeFitter::FitMode::PreferredSize);
    contentSizeFitter->set_verticalFit(ContentSizeFitter::FitMode::PreferredSize);

    return openButton;
}

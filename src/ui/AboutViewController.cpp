#include "ui/AboutViewController.hpp"
#include "UnityEngine/Application.hpp"

DEFINE_TYPE(PeripheralHUD::UI, AboutViewController);

void PeripheralHUD::UI::AboutViewController::DidActivate(
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    using namespace UnityEngine;

    if (firstActivation) {
        GameObject* container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(get_transform());

        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "<size=200%>PeripheralHUD", false);
        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "Commissioned by Inderix, developed by Kaitlyn.", true);

        QuestUI::BeatSaberUI::CreateUIButton(container->get_transform(), "Check out Inderix on Twitter (@CorruptInderix)",
            []() {
                Application::OpenURL("https://twitter.com/CorruptInderix");
            }
        );

        QuestUI::BeatSaberUI::CreateUIButton(container->get_transform(), "Check out Kaitlyn on Twitter (@ItsKaitlyn03)",
            []() {
                Application::OpenURL("https://twitter.com/ItsKaitlyn03");
            }
        );

        QuestUI::BeatSaberUI::CreateText(container->get_transform(), "<size=150%>If you like my work, please consider donating!", true);
        QuestUI::BeatSaberUI::CreateUIButton(container->get_transform(), "Donate",
            []() {
                Application::OpenURL("https://www.patreon.com/join/ItsKaitlyn03");
            }
        );
    }
}

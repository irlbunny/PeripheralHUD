#include "custom/CustomHUDController.hpp"
#include "GlobalNamespace/ComboUIController.hpp"
#include "GlobalNamespace/CoreGameHUDController.hpp"
#include "GlobalNamespace/GameEnergyUIPanel.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/ImmediateRankUIPanel.hpp"
#include "GlobalNamespace/ScoreMultiplierUIController.hpp"
#include "UnityEngine/RenderMode.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Object.hpp"
#include "config.hpp"

DEFINE_TYPE(PeripheralHUD, CustomHUDController);

// WHY IS THIS STRIPPED?!?!
void set_planeDistance(UnityEngine::Canvas* canvas, float value) {
    using namespace UnityEngine;
    
    static auto set_planeDistance_Internal = reinterpret_cast<function_ptr_t<void, Canvas*, float>>(il2cpp_functions::resolve_icall("UnityEngine.Canvas::set_planeDistance"));
    set_planeDistance_Internal(canvas, value);
}

void PeripheralHUD::CustomHUDController::Reload() {
    using namespace UnityEngine;

    // Combo
    worldComboUIControllerGO->SetActive(!getPeripheralHUDConfig().HideWorldCombo.GetValue());
    cameraComboUIControllerWrapperGO->SetActive(!getPeripheralHUDConfig().HideCameraCombo.GetValue());
    Vector3 cameraComboUIControllerWrapperPosition = cameraComboUIControllerWrapperGO->get_transform()->get_localPosition();
    cameraComboUIControllerWrapperPosition.x = getPeripheralHUDConfig().ComboPositionX.GetValue();
    cameraComboUIControllerWrapperPosition.y = getPeripheralHUDConfig().ComboPositionY.GetValue();
    cameraComboUIControllerWrapperGO->get_transform()->set_localPosition(cameraComboUIControllerWrapperPosition);
    Vector3 cameraComboUIControllerWrapperScale = cameraComboUIControllerWrapperGO->get_transform()->get_localScale();
    cameraComboUIControllerWrapperScale.x = getPeripheralHUDConfig().ComboScale.GetValue();
    cameraComboUIControllerWrapperScale.y = getPeripheralHUDConfig().ComboScale.GetValue();
    cameraComboUIControllerWrapperGO->get_transform()->set_localScale(cameraComboUIControllerWrapperScale);
    
    // Score
    worldImmediateRankUIPanelGO->SetActive(!getPeripheralHUDConfig().HideWorldScore.GetValue());
    cameraImmediateRankUIPanelWrapperGO->SetActive(!getPeripheralHUDConfig().HideCameraScore.GetValue());
    Vector3 cameraImmediateRankUIPanelWrapperPosition = cameraImmediateRankUIPanelWrapperGO->get_transform()->get_localPosition();
    cameraImmediateRankUIPanelWrapperPosition.x = getPeripheralHUDConfig().ScorePositionX.GetValue();
    cameraImmediateRankUIPanelWrapperPosition.y = getPeripheralHUDConfig().ScorePositionY.GetValue();
    cameraImmediateRankUIPanelWrapperGO->get_transform()->set_localPosition(cameraImmediateRankUIPanelWrapperPosition);
    Vector3 cameraImmediateRankUIPanelWrapperScale = cameraImmediateRankUIPanelWrapperGO->get_transform()->get_localScale();
    cameraImmediateRankUIPanelWrapperScale.x = getPeripheralHUDConfig().ScoreScale.GetValue();
    cameraImmediateRankUIPanelWrapperScale.y = getPeripheralHUDConfig().ScoreScale.GetValue();
    cameraImmediateRankUIPanelWrapperGO->get_transform()->set_localScale(cameraImmediateRankUIPanelWrapperScale);

    // Multiplier
    worldScoreMultiplierUIControllerGO->SetActive(!getPeripheralHUDConfig().HideWorldMultiplier.GetValue());
    cameraScoreMultiplierUIControllerWrapperGO->SetActive(!getPeripheralHUDConfig().HideCameraMultiplier.GetValue());
    Vector3 cameraScoreMultiplierUIControllerWrapperPosition = cameraScoreMultiplierUIControllerWrapperGO->get_transform()->get_localPosition();
    cameraScoreMultiplierUIControllerWrapperPosition.x = getPeripheralHUDConfig().MultiplierPositionX.GetValue();
    cameraScoreMultiplierUIControllerWrapperPosition.y = getPeripheralHUDConfig().MultiplierPositionY.GetValue();
    cameraScoreMultiplierUIControllerWrapperGO->get_transform()->set_localPosition(cameraScoreMultiplierUIControllerWrapperPosition);
    Vector3 cameraScoreMultiplierUIControllerWrapperScale = cameraScoreMultiplierUIControllerWrapperGO->get_transform()->get_localScale();
    cameraScoreMultiplierUIControllerWrapperScale.x = getPeripheralHUDConfig().MultiplierScale.GetValue();
    cameraScoreMultiplierUIControllerWrapperScale.y = getPeripheralHUDConfig().MultiplierScale.GetValue();
    cameraScoreMultiplierUIControllerWrapperGO->get_transform()->set_localScale(cameraScoreMultiplierUIControllerWrapperScale);
}

void PeripheralHUD::CustomHUDController::Initialize(Zenject::DiContainer* container, UnityEngine::GameObject* rootObject) {
    using namespace GlobalNamespace;
    using namespace UnityEngine;

    MainCamera* mainCamera = container->Resolve<MainCamera*>();
    GameObject* coreGameHUDControllerGO = rootObject->GetComponentInChildren<CoreGameHUDController*>(true)->get_gameObject();

    // Combo
    worldComboUIControllerGO = coreGameHUDControllerGO->GetComponentInChildren<ComboUIController*>(true)->get_gameObject();
    cameraComboUIControllerGO = container->InstantiatePrefab(worldComboUIControllerGO, get_transform());

    InitializeCanvas(cameraComboUIControllerGO->GetComponent<Canvas*>(), mainCamera->camera);

    cameraComboUIControllerWrapperGO = CreateRectTransformWrapper(cameraComboUIControllerGO);

    // Score
    worldImmediateRankUIPanelGO = coreGameHUDControllerGO->GetComponentInChildren<ImmediateRankUIPanel*>(true)->get_gameObject();
    cameraImmediateRankUIPanelGO = container->InstantiatePrefab(worldImmediateRankUIPanelGO, get_transform());

    InitializeCanvas(cameraImmediateRankUIPanelGO->GetComponent<Canvas*>(), mainCamera->camera);

    cameraImmediateRankUIPanelWrapperGO = CreateRectTransformWrapper(cameraImmediateRankUIPanelGO);

    // Multiplier
    worldScoreMultiplierUIControllerGO = coreGameHUDControllerGO->GetComponentInChildren<ScoreMultiplierUIController*>(true)->get_gameObject();
    cameraScoreMultiplierUIControllerGO = container->InstantiatePrefab(worldScoreMultiplierUIControllerGO, get_transform());

    InitializeCanvas(cameraScoreMultiplierUIControllerGO->GetComponent<Canvas*>(), mainCamera->camera);

    cameraScoreMultiplierUIControllerWrapperGO = CreateRectTransformWrapper(cameraScoreMultiplierUIControllerGO);

    Reload();
}

void PeripheralHUD::CustomHUDController::InitializeCanvas(UnityEngine::Canvas* canvas, UnityEngine::Camera* camera) {
    using namespace UnityEngine;
    
    canvas->set_worldCamera(camera);
    canvas->set_renderMode(RenderMode::ScreenSpaceCamera);
    set_planeDistance(canvas, .5f);
    canvas->set_sortingOrder(1000);
}

// Required because ScreenSpaceCamera is a mess.
UnityEngine::GameObject* PeripheralHUD::CustomHUDController::CreateRectTransformWrapper(UnityEngine::GameObject* rootObject) {
    using namespace System;
    using namespace UnityEngine;
    
    ArrayW<Type*> components(1);
    components[0] = csTypeOf(RectTransform*);
    GameObject* wrapperGO = GameObject::New_ctor("Wrapper", components);
    wrapperGO->get_transform()->SetParent(rootObject->get_transform(), false);

    // propagation
    std::vector<Transform*> childTransforms{};
    for (int32_t i = 0; i < rootObject->get_transform()->get_childCount(); i++) {
        Transform* childTransform = rootObject->get_transform()->GetChild(i);
        if (childTransform->get_gameObject() == wrapperGO) {
            continue;
        }
        childTransforms.push_back(childTransform);
    }
    
    for (Transform* childTransform : childTransforms) {
        childTransform->SetParent(wrapperGO->get_transform(), false);
    }

    return wrapperGO;
}

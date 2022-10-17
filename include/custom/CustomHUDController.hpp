#pragma once
#include "plugin.hpp"
#include "GlobalNamespace/MainCamera.hpp"
#include "UnityEngine/Camera.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/MonoBehaviour.hpp"
#include "Zenject/DiContainer.hpp"

DECLARE_CLASS_CODEGEN(PeripheralHUD, CustomHUDController, UnityEngine::MonoBehaviour,
    // Combo
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, worldComboUIControllerGO);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, cameraComboUIControllerGO);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, cameraComboUIControllerWrapperGO);

    // Score
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, worldImmediateRankUIPanelGO);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, cameraImmediateRankUIPanelGO);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, cameraImmediateRankUIPanelWrapperGO);

    // Multiplier
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, worldScoreMultiplierUIControllerGO);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, cameraScoreMultiplierUIControllerGO);
    DECLARE_INSTANCE_FIELD(UnityEngine::GameObject*, cameraScoreMultiplierUIControllerWrapperGO);
    
    DECLARE_INSTANCE_METHOD(void, Reload);
    DECLARE_INSTANCE_METHOD(void, Initialize, Zenject::DiContainer* container, UnityEngine::GameObject* rootObject);
    DECLARE_INSTANCE_METHOD(void, InitializeCanvas, UnityEngine::Canvas* canvas, UnityEngine::Camera* camera);
    DECLARE_INSTANCE_METHOD(UnityEngine::GameObject*, CreateRectTransformWrapper, UnityEngine::GameObject* rootObject);
)

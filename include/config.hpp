#pragma once
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(PeripheralHUDConfig,
    // Combo
    CONFIG_VALUE(HideWorldCombo, bool, "HideWorldCombo", false);
    CONFIG_VALUE(HideCameraCombo, bool, "HideCameraCombo", false);

    CONFIG_VALUE(ComboPositionX, float, "ComboPositionX", -250.f);
    CONFIG_VALUE(ComboPositionY, float, "ComboPositionY", 200.f);
    CONFIG_VALUE(ComboScale, float, "ComboScale", 1.f);

    // Score
    CONFIG_VALUE(HideWorldScore, bool, "HideWorldScore", false);
    CONFIG_VALUE(HideCameraScore, bool, "HideCameraScore", false);

    CONFIG_VALUE(ScorePositionX, float, "ScorePositionX", -250.f);
    CONFIG_VALUE(ScorePositionY, float, "ScorePositionY", -150.f);
    CONFIG_VALUE(ScoreScale, float, "ScoreScale", 2.f);

    // Multiplier
    CONFIG_VALUE(HideWorldMultiplier, bool, "HideWorldMultiplier", false);
    CONFIG_VALUE(HideCameraMultiplier, bool, "HideCameraMultiplier", false);

    CONFIG_VALUE(MultiplierPositionX, float, "MultiplierPositionX", 250.f);
    CONFIG_VALUE(MultiplierPositionY, float, "MultiplierPositionY", 200.f);
    CONFIG_VALUE(MultiplierScale, float, "MultiplierScale", 1.f);

    CONFIG_INIT_FUNCTION(
        // Combo
        CONFIG_INIT_VALUE(HideWorldCombo);
        CONFIG_INIT_VALUE(HideCameraCombo);

        CONFIG_INIT_VALUE(ComboPositionX);
        CONFIG_INIT_VALUE(ComboPositionY);
        CONFIG_INIT_VALUE(ComboScale);

        // Score
        CONFIG_INIT_VALUE(HideWorldScore);
        CONFIG_INIT_VALUE(HideCameraScore);

        CONFIG_INIT_VALUE(ScorePositionX);
        CONFIG_INIT_VALUE(ScorePositionY);
        CONFIG_INIT_VALUE(ScoreScale);

        // Multiplier
        CONFIG_INIT_VALUE(HideWorldMultiplier);
        CONFIG_INIT_VALUE(HideCameraMultiplier);

        CONFIG_INIT_VALUE(MultiplierPositionX);
        CONFIG_INIT_VALUE(MultiplierPositionY);
        CONFIG_INIT_VALUE(MultiplierScale);
    )
)

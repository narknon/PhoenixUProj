#include "SceneAction_RenderSettings.h"

USceneAction_RenderSettings::USceneAction_RenderSettings() {
    this->ExposureTweak = 0.00f;
    this->FeatherInTime = 0.50f;
    this->FeatherOutTime = 0.50f;
    this->Priority = 10000.00f;
    this->bEnabled = true;
    this->bUseExposureTweak = false;
}


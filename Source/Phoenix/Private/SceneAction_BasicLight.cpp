#include "SceneAction_BasicLight.h"

USceneAction_BasicLight::USceneAction_BasicLight() {
    this->Source = NULL;
    this->Target = NULL;
    this->bStationary = false;
    this->bPreviewOnly = false;
    this->bUseOnOffCurve = false;
    this->bUseIntensityCurve = false;
    this->bUseAttenuationCurve = false;
    this->bUseColorCurve = false;
    this->bUseOuterConeAngleCurve = false;
    this->bNormalizeCurvesToInterval = false;
}


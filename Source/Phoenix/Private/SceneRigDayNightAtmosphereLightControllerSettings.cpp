#include "SceneRigDayNightAtmosphereLightControllerSettings.h"

USceneRigDayNightAtmosphereLightControllerSettings::USceneRigDayNightAtmosphereLightControllerSettings() {
    this->Intensity = NULL;
    this->BaseIntensityFactor = 1.00f;
    this->Desaturation = NULL;
    this->ColorOp = EDayNightLightControllerOp::ModulateLightValue;
    this->IntensityOp = EDayNightLightControllerOp::ModulateLightValue;
}


#include "DynamicCharacterLightRigLightUpdate.h"

FDynamicCharacterLightRigLightUpdate::FDynamicCharacterLightRigLightUpdate() {
    this->Owner = NULL;
    this->DayNightLerp = 0.00f;
    this->TemperatureMod = 0.00f;
    this->IntensityMod = 0.00f;
    this->Adaptation = 0.00f;
    this->DirectionalLightIntensity = 0.00f;
    this->DirectionalLightAzimuthDegrees = 0.00f;
    this->DirectionalLightAltitudeDegrees = 0.00f;
    this->bDirectionalLight = false;
    this->bEnabled = false;
}


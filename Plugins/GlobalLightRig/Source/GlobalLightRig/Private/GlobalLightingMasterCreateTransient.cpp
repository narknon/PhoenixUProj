#include "GlobalLightingMasterCreateTransient.h"

FGlobalLightingMasterCreateTransient::FGlobalLightingMasterCreateTransient() {
    this->DefaultsOverride = NULL;
    this->UseExternalLightingComponents = 0;
    this->ControlLightingComponents = 0;
    this->HideExtraLightingComponents = 0;
    this->ControlFeatures = 0;
    this->bWantClouds = false;
    this->CloudsRelativeHeightMeters = 0.00f;
    this->bSetCloudsRelativeHeightMeters = false;
}


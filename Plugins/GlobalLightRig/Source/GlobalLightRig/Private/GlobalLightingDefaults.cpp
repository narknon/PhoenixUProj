#include "GlobalLightingDefaults.h"

UGlobalLightingDefaults::UGlobalLightingDefaults() {
    this->SingleDirectionalLightMaterialOverride = NULL;
    this->DualDirectionalLightMaterialOverride = NULL;
    this->bCameraExpHeightFogHeight = false;
    this->bCloudSceneLightingDefaultToDirectionalLight = false;
}


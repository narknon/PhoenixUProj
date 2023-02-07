#include "AkGeometrySurfaceOverride.h"

FAkGeometrySurfaceOverride::FAkGeometrySurfaceOverride() {
    this->AcousticTexture = NULL;
    this->bEnableOcclusionOverride = false;
    this->OcclusionValue = 0.00f;
    this->SurfaceArea = 0.00f;
}


#include "VolumetricCloudsGroundShadowsParams.h"

FVolumetricCloudsGroundShadowsParams::FVolumetricCloudsGroundShadowsParams() {
    this->Material = NULL;
    this->MPC = NULL;
    this->LightFunctionScaleFactor = 0.00f;
    this->Opacity = 0.00f;
    this->Sharpening = 0.00f;
    this->WindMultiplier = 0.00f;
    this->DensityVsPreMultiply = NULL;
    this->HardnessVsLightHeight = NULL;
    this->bModulateByLightHeight = false;
}


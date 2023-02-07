#include "DirectionalLightShafts.h"

FDirectionalLightShafts::FDirectionalLightShafts() {
    this->bEnableLightShaftOcclusion = false;
    this->OcclusionMaskDarkness = 0.00f;
    this->OcclusionDepthRange = 0.00f;
    this->bEnableLightShaftBloom = false;
    this->BloomScale = 0.00f;
    this->BloomThreshold = 0.00f;
}


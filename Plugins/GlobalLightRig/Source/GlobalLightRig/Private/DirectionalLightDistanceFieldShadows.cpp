#include "DirectionalLightDistanceFieldShadows.h"

FDirectionalLightDistanceFieldShadows::FDirectionalLightDistanceFieldShadows() {
    this->bUseRayTracedDistanceFieldShadows = false;
    this->RayStartOffsetDepthScale = 0.00f;
    this->DistanceFieldShadowDistance = 0.00f;
    this->TraceDistance = 0.00f;
}


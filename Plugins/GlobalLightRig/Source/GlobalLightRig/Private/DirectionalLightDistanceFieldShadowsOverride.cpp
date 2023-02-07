#include "DirectionalLightDistanceFieldShadowsOverride.h"

FDirectionalLightDistanceFieldShadowsOverride::FDirectionalLightDistanceFieldShadowsOverride() {
    this->bOverride_UseRayTracedDistanceFieldShadows = false;
    this->bOverride_RayStartOffsetDepthScale = false;
    this->bOverride_DistanceFieldShadowDistance = false;
    this->bOverride_TraceDistance = false;
    this->bUseRayTracedDistanceFieldShadows = false;
    this->RayStartOffsetDepthScale = 0.00f;
    this->DistanceFieldShadowDistance = 0.00f;
    this->TraceDistance = 0.00f;
}


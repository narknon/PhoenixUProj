#include "GroundSwarmingExternalForce.h"

FGroundSwarmingExternalForce::FGroundSwarmingExternalForce() {
    this->Type = EGroundSwarmingExternalForceType::Forward;
    this->InnerForce = 0.00f;
    this->InnerRadius = 0.00f;
    this->OuterForce = 0.00f;
    this->OuterRadius = 0.00f;
    this->CurlNoiseXYScaling = 0.00f;
    this->CurlNoiseEpsilon = 0.00f;
    this->bOuterForceUnbounded = false;
    this->bUseXYDistance = false;
    this->bSurfaceOnly = false;
    this->bEnabled = false;
}


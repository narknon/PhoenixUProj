#include "HoudiniAssetComponent.h"

int32 UHoudiniAssetComponent::GetAssetId() const {
    return 0;
}

UHoudiniAssetComponent::UHoudiniAssetComponent() {
    this->bGeneratedDoubleSidedGeometry = false;
    this->GeneratedPhysMaterial = NULL;
    this->GeneratedCollisionTraceFlag = CTF_UseDefault;
    this->GeneratedLightMapResolution = 32;
    this->GeneratedLpvBiasMultiplier = 1.00f;
    this->GeneratedDistanceFieldResolutionScale = 0.00f;
    this->GeneratedLightMapCoordinateIndex = 1;
    this->bGeneratedUseMaximumStreamingTexelRatio = false;
    this->GeneratedStreamingDistanceMultiplier = 1.00f;
    this->GeneratedFoliageDefaultSettings = NULL;
}


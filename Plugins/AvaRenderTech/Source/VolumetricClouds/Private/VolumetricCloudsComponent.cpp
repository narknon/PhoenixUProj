#include "VolumetricCloudsComponent.h"

UVolumetricCloudsComponent::UVolumetricCloudsComponent() {
    this->Height = 65000.00f;
    this->HeightOffset = 0.00f;
    this->GroundShadowsStrength = 1.00f;
    this->GroundShadowsState = NULL;
    this->bIsIntro = false;
    this->VisibilityGroupMask = EVisibilityGroupMask::Unset;
}


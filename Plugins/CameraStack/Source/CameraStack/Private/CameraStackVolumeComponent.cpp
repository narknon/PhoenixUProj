#include "CameraStackVolumeComponent.h"

UCameraStackVolumeComponent::UCameraStackVolumeComponent() {
    this->VolumePreset = NULL;
    this->Priority = 0;
    this->weight = 1.00f;
    this->BlendRadius = 200.00f;
    this->MaxCrossBlendSpeed = 1.00f;
}


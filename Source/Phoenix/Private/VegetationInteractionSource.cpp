#include "VegetationInteractionSource.h"

FVegetationInteractionSource::FVegetationInteractionSource() {
    this->Priority = 0.00f;
    this->InnerRadius = 0.00f;
    this->OuterRadius = 0.00f;
    this->ForceScalingMultiplier = 0.00f;
    this->MaxAngleMultiplier = 0.00f;
    this->CameraFadeBaseZ = 0.00f;
    this->CameraDistanceSquared = 0.00f;
    this->bOnCamera = false;
}


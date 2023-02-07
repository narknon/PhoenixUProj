#include "VegetationInteractionCameraFade.h"

FVegetationInteractionCameraFade::FVegetationInteractionCameraFade() {
    this->CapsuleInnerRadiusAtCamera = 0.00f;
    this->CapsuleOuterRadiusAtCamera = 0.00f;
    this->CapsuleInnerRadiusAtTarget = 0.00f;
    this->CapsuleOuterRadiusAtTarget = 0.00f;
    this->FadeFalloffPower = 0.00f;
    this->AspectRatio = 0.00f;
    this->Strength = 0.00f;
    this->MinimumVegetationHeight = 0.00f;
    this->PlayerZOffset = 0.00f;
    this->TargetZOffset = 0.00f;
    this->TargetRelativeDistanceMeters = 0.00f;
    this->PlayerTargetLerp = 0.00f;
}


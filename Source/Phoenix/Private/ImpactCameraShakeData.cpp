#include "ImpactCameraShakeData.h"

FImpactCameraShakeData::FImpactCameraShakeData() {
    this->CameraShake = NULL;
    this->InnerRadius = 0.00f;
    this->OuterRadius = 0.00f;
    this->Falloff = 0.00f;
    this->bOrientShakeTowardsEpicenter = false;
    this->ForceFeedbackEffect = NULL;
}


#include "MultiFX2_CameraShake.h"

UMultiFX2_CameraShake::UMultiFX2_CameraShake() {
    this->CameraShake = NULL;
    this->InnerRadius = 100.00f;
    this->OuterRadius = 1000.00f;
    this->Falloff = 1.00f;
    this->bOrientShakeTowardsEpicenter = true;
}


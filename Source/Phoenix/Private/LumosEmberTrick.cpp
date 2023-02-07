#include "LumosEmberTrick.h"

ULumosEmberTrick::ULumosEmberTrick() {
    this->RadiusCurve = NULL;
    this->RotationCurve = NULL;
    this->TrickAxis = EEmberTrickAxis::XAxis;
    this->TrickRotation = EEmberTrickRotation::Yaw;
    this->RadiusValueMultiplier = 1.00f;
    this->RadiusTimeMultiplier = 1.00f;
    this->RotationValueMultiplier = 1.00f;
    this->RotationTimeMultiplier = 1.00f;
}


#include "AblSlopeSlideTask.h"

UAblSlopeSlideTask::UAblSlopeSlideTask() {
    this->DesiredSlopeSpeed = 1.00f;
    this->SlopeVelocityInterpType = ECustomInterpType::EaseIn;
    this->SlopeVelocityInterpSpeed = 1.00f;
    this->ToFlatGroundInterpType = ECustomInterpType::EaseIn;
    this->ToFlatGroundInterpSpeed = 1.00f;
    this->SlopeFriction = 0.00f;
}


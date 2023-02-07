#include "BlendSpaceInput_GForce.h"

UBlendSpaceInput_GForce::UBlendSpaceInput_GForce() {
    this->ActorToGetAccelerationFrom = NULL;
    this->Alpha = NULL;
    this->HorizontalAxis = EAxisMapping::PositiveX;
    this->VerticalAxis = EAxisMapping::PositiveX;
}


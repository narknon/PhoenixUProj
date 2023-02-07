#include "FinisherRequirementData.h"

FFinisherRequirementData::FFinisherRequirementData() {
    this->bRequireMinDistance = false;
    this->MinDistance = 0.00f;
    this->bRequireMaxDistance = false;
    this->MaxDistance = 0.00f;
    this->bMustBeOnGround = false;
    this->bMustBeInAir = false;
    this->bMustBeArmed = false;
}


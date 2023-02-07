#include "FXUpdate_KeepOnGround.h"

UFXUpdate_KeepOnGround::UFXUpdate_KeepOnGround() {
    this->MaxDistance = 500.00f;
    this->InterpolationWeight = 1.00f;
    this->bPlayIfNoGround = true;
    this->bOrientToGround = false;
    this->bReApplyAdjustments = true;
}


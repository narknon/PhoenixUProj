#include "FXAdjustments_OnGround.h"

UFXAdjustments_OnGround::UFXAdjustments_OnGround() {
    this->TraceDistance = 500.00f;
    this->TraceRadius = 10.00f;
    this->bPlayIfNoGround = false;
    this->bUseGroundTarget = true;
    this->bUseGroundPosition = true;
    this->bUseGoundNormalOrientation = true;
}


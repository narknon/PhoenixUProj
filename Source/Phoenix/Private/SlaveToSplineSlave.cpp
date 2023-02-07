#include "SlaveToSplineSlave.h"

FSlaveToSplineSlave::FSlaveToSplineSlave() {
    this->Slave = NULL;
    this->Mode = ESlaveToSplineUpdateMode::Wrap;
    this->DurationFactor = 0.00f;
    this->SplineT = 0.00f;
    this->SplineTReset = 0.00f;
    this->bUseConstantVelocity = false;
    this->bPositionOnly = false;
    this->bIncludeScale = false;
    this->bReverseDirection = false;
    this->bDisableCollision = false;
    this->bFollowEnabled = false;
}


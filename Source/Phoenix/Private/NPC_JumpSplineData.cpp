#include "NPC_JumpSplineData.h"

FNPC_JumpSplineData::FNPC_JumpSplineData() {
    this->SplinePtr = NULL;
    this->bLimitMinMaxSpeed = false;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->SpeedScale = 0.00f;
    this->GravityScalePostApex = 0.00f;
    this->GravityScalePostApexInterpRate = 0.00f;
    this->bOverrideStartSpeed = false;
    this->OverrideStartSpeed = 0.00f;
    this->bOverrideGravity = false;
    this->OverrideGravity = 0.00f;
    this->RotateToFaceRate = 0.00f;
    this->InterpToSplineInitialRate = 0.00f;
    this->InterpToSplineRate = 0.00f;
}


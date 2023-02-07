#include "CameraFixupSetAnglesOperation.h"

UCameraFixupSetAnglesOperation::UCameraFixupSetAnglesOperation() {
    this->DrawDebug = false;
    this->Relative = false;
    this->SetPitch = false;
    this->PitchAngle = 0.00f;
    this->PitchAngleProvider = NULL;
    this->SetYaw = false;
    this->YawAngle = 0.00f;
    this->YawAngleProvider = NULL;
    this->SetRoll = false;
    this->RollAngle = 0.00f;
    this->RollAngleProvider = NULL;
}


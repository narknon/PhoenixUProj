#include "CameraFixupSetPositionTumbleMethod.h"

UCameraFixupSetPositionTumbleMethod::UCameraFixupSetPositionTumbleMethod() {
    this->Target = NULL;
    this->DrawDebug = false;
    this->Distance = 0.00f;
    this->DistanceProvider = NULL;
    this->PitchAngle = 0.00f;
    this->PitchAngleProvider = NULL;
    this->YawAngle = 0.00f;
    this->YawAngleProvider = NULL;
}


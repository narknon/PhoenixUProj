#include "CameraFixupAimWithPivotOperation.h"

UCameraFixupAimWithPivotOperation::UCameraFixupAimWithPivotOperation() {
    this->AimTarget = NULL;
    this->DrawDebug = false;
    this->EnableTargetLag = false;
    this->TargetLagSpeed = 0.00f;
    this->TargetLagSpeedProvider = NULL;
    this->TargetLagMaxDistance = 0.00f;
    this->TargetLagMaxDistanceProvider = NULL;
    this->DrawDebugLagMarkers = false;
}


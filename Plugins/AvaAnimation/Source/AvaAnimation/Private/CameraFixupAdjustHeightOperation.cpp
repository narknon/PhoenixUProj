#include "CameraFixupAdjustHeightOperation.h"

UCameraFixupAdjustHeightOperation::UCameraFixupAdjustHeightOperation() {
    this->HeightTarget = NULL;
    this->HeightOffset = 0.00f;
    this->HeightOffsetProvider = NULL;
    this->DrawDebug = false;
    this->EnableTargetLag = false;
    this->TargetLagSpeed = 0.00f;
    this->TargetLagSpeedProvider = NULL;
    this->TargetLagMaxDistance = 0.00f;
    this->TargetLagMaxDistanceProvider = NULL;
    this->DrawDebugLagMarkers = false;
}


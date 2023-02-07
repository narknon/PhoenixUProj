#include "TraversalDetectionSettings.h"

FTraversalDetectionSettings::FTraversalDetectionSettings() {
    this->MinLedgeHeight = 0.00f;
    this->MaxLedgeHeight = 0.00f;
    this->SweepRadius = 0.00f;
    this->SweepDistance = 0.00f;
    this->SweepLookAheadTime = 0.00f;
    this->VerticalTrajectoryLookAheadTime = 0.00f;
    this->LedgeMaxWallAngleToInput = 0.00f;
    this->LedgeCheckRadius = 0.00f;
    this->LedgeCheckHalfHeight = 0.00f;
    this->LedgeCheckTiltAngle = 0.00f;
    this->CapsuleSizeCheckRadius = 0.00f;
    this->CapsuleSizeCheckHalfHeight = 0.00f;
    this->CharacterCapsuleDefaultHalfHeight = 0.00f;
    this->MaxVaultDistance = 0.00f;
    this->VaultHeightPastObstacle = 0.00f;
    this->MaxWallHangAngle = 0.00f;
    this->BlockingWallStoppingDistance = 0.00f;
    this->MaxBlockingWallAngle = 0.00f;
    this->BlockingWallAngleHysteresis = 0.00f;
    this->BlockingWallCheckMaxWalkableFloorAngle = 0.00f;
}


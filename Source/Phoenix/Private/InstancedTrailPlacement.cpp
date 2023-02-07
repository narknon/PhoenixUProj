#include "InstancedTrailPlacement.h"

FInstancedTrailPlacement::FInstancedTrailPlacement() {
    this->bInitialRotation = false;
    this->RandomRotationDegrees = 0.00f;
    this->bRandomRotation = false;
    this->UpDown = 0.00f;
    this->bUpDown = false;
    this->LeftRight = 0.00f;
    this->bLeftRight = false;
    this->ForeAft = 0.00f;
    this->bForeAft = false;
    this->DirRotation = 0.00f;
    this->bDirRotation = false;
    this->bOnGround = false;
    this->OnGroundTraceDepth = 0.00f;
    this->OnGroundZTweak = 0.00f;
    this->OnGroundZTweakRandomizePercent = 0.00f;
}


#include "CameraFixupAdjustBoneFraming.h"

UCameraFixupAdjustBoneFraming::UCameraFixupAdjustBoneFraming() {
    this->TargetBone = NULL;
    this->ReferenceBone = NULL;
    this->DeadDistanceProvider = NULL;
    this->bRotate = true;
    this->WeightProvider = NULL;
    this->DrawDebug = false;
}


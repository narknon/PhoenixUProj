#include "CameraStackBehaviorKeepLineOfSight.h"

UCameraStackBehaviorKeepLineOfSight::UCameraStackBehaviorKeepLineOfSight() {
    this->bDrawDebug = false;
    this->MaximumAngleInRadians = 1.57f;
    this->WalkAxisToMaxAngleScaleCurve = NULL;
    this->SweepCountPerUpdate = 1;
    this->SecondsBetweenSweeps = 0.00f;
    this->StepSizeInRadians = 0.10f;
    this->RotationSpeed = 1.50f;
    this->InterpSpeed = 2.00f;
    this->RotationSpeedTight = 2.00f;
    this->InterpSpeedTight = 3.00f;
    this->CollisionProximityTimeToSpeedAlpha = NULL;
    this->LineOfSightProbeChannel = ECC_Camera;
    this->LineOfSightProbeSize = 0.00f;
    this->TraceTagName = TEXT("SpringArm");
}


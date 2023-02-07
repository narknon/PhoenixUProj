#include "CameraStackBehaviorLineOfSightDistance.h"

UCameraStackBehaviorLineOfSightDistance::UCameraStackBehaviorLineOfSightDistance() {
    this->bDrawDebug = false;
    this->MaximumAngleInDegrees = 90.00f;
    this->SweepCountPerUpdate = 1;
    this->SecondsBetweenSweeps = 0.00f;
    this->StepSizeInDegrees = 5.73f;
    this->ProbeChannel = ECC_Camera;
    this->ProbeSize = 12.00f;
    this->SweepLength = 600.00f;
    this->TraceTagName = TEXT("SpringArm");
    this->MinArmLength = 50.00f;
    this->MinTargetMovingSpeed = 40.00f;
    this->MinTargetMovingTime = 0.50f;
    this->CameraReturnSpeed = 2.00f;
}


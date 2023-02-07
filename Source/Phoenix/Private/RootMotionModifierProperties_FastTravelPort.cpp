#include "RootMotionModifierProperties_FastTravelPort.h"

URootMotionModifierProperties_FastTravelPort::URootMotionModifierProperties_FastTravelPort() {
    this->bAllowYawRotation = true;
    this->YawToTargetThreshold = 0.00f;
    this->TimeToRotateToTarget = 0.00f;
    this->bAllowTranslation = true;
    this->TimeToTranslateToTarget = 0.00f;
    this->bDebug = false;
}


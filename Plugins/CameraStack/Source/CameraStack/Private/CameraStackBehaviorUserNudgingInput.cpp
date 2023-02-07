#include "CameraStackBehaviorUserNudgingInput.h"

UCameraStackBehaviorUserNudgingInput::UCameraStackBehaviorUserNudgingInput() {
    this->MaxYaw = 20.00f;
    this->MaxPitch = 10.00f;
    this->SmoothingFrequency = 10.00f;
    this->SmoothingDampingRatio = 1.75f;
    this->InputMappingCurve = NULL;
}


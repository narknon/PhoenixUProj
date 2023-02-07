#include "CameraStackCameraLookAtTargetGetter.h"

UCameraStackCameraLookAtTargetGetter::UCameraStackCameraLookAtTargetGetter() {
    this->LookAtStrength = ECameraStackLookAtStrength::Strong;
    this->bReturnHigherStrengthTargets = false;
}


#include "CameraActionTransitionSettings.h"

FCameraActionTransitionSettings::FCameraActionTransitionSettings() {
    this->BlendTime = NULL;
    this->ResetType = ECameraStackResetType::NoReset;
    this->ResetLookAtLocation = NULL;
    this->bLazyBlend = false;
    this->bOldCameraStaysValid = false;
}


#include "SceneRigVariant.h"

FSceneRigVariant::FSceneRigVariant() {
    this->AvoidTwiceInARow = false;
    this->MinRepeatLimitCount = 0;
    this->MaxRepeatLimitCount = 0;
    this->MinRepeatDelayLimitSeconds = 0.00f;
    this->MaxRepeatDelayLimitSeconds = 0.00f;
    this->RelativeWeight = 0.00f;
    this->SceneRig = NULL;
}


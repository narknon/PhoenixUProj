#include "SceneAction_CameraStackSetup.h"

USceneAction_CameraStackSetup::USceneAction_CameraStackSetup() {
    this->CameraTargetTransform = NULL;
    this->CameraStack = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->InputPriorityOverride = -1;
}


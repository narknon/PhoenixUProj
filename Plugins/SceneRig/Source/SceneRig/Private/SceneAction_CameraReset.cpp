#include "SceneAction_CameraReset.h"

USceneAction_CameraReset::USceneAction_CameraReset() {
    this->ResetType = ECameraStackResetType::FullReset;
    this->ResetLookAtLocation = NULL;
}


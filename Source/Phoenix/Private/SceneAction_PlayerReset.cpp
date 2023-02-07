#include "SceneAction_PlayerReset.h"

USceneAction_PlayerReset::USceneAction_PlayerReset() {
    this->TeleportTransform = NULL;
    this->CameraResetType = ECameraStackResetType::FullReset;
    this->CameraResetLookAtLocation = NULL;
}


#include "SceneAction_Camera.h"

USceneAction_Camera::USceneAction_Camera() {
    this->Priority = EManagedCameraPriority::Lowest;
    this->Camera = NULL;
    this->bCameraTransitionOutDelayed = false;
    this->InitialCamera = NULL;
    this->FinalCamera = NULL;
    this->BlendTime = NULL;
    this->BlendTimeIntoGameCamera = NULL;
    this->bLazyBlendIntoGameCamera = false;
    this->GameCameraResetType = ESceneAction_CameraResetType::CurrentCameraYawAndDefaultPitch;
    this->GameCameraLookAtLocation = NULL;
}


#include "SceneRigCameraProxyActor.h"

USceneRigCameraProxyActor::USceneRigCameraProxyActor() {
    this->RegisteredCameraName = NULL;
    this->RegisterCamera = true;
    this->CheckObstructions = false;
    this->CheckTransitions = false;
    this->ValidCameraType = ESceneRigCameraProxyActor_ValidCameraType::CheckObstructions;
}


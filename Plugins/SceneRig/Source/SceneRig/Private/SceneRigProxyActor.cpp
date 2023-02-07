#include "SceneRigProxyActor.h"

USceneRigProxyActor::USceneRigProxyActor() {
    this->Actor = NULL;
    this->bInterestPoint = false;
    this->ShouldHoldDuringInitialization = true;
    this->HideOnPlatforms = ESceneRigProxyActor_PlatformHide::None;
}


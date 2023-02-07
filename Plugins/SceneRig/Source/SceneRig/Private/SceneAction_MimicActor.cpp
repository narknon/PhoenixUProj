#include "SceneAction_MimicActor.h"

USceneAction_MimicActor::USceneAction_MimicActor() {
    this->ActorToMimic = NULL;
    this->bMimicVisibility = true;
    this->bMimicAnimation = true;
    this->bMimicTransform = true;
    this->bFlipAroundFloor = false;
    this->FloorZ = 0.00f;
}


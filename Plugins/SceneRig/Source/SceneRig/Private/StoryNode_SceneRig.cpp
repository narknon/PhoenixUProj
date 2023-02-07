#include "StoryNode_SceneRig.h"

class UObject;
class USceneRig;

USceneRig* UStoryNode_SceneRig::GetSceneRigBP(const UObject* Caller) {
    return NULL;
}

UStoryNode_SceneRig::UStoryNode_SceneRig() {
    this->StorySR = NULL;
    this->InitializingBehavior = ETimeRigInitializingBehavior::UseSRSettings;
    this->bSkippable = false;
}


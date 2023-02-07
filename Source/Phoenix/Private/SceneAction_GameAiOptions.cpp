#include "SceneAction_GameAiOptions.h"

USceneAction_GameAiOptions::USceneAction_GameAiOptions() {
    this->bOverrideAreCharactersInSceneTargetableByAi = false;
    this->bAreCharactersInSceneTargetableByAi = false;
    this->TargetableByAiPriority = EStandardManagedPriority::PassiveCinematic;
    this->bOverrideAreNpcsSuspended = false;
    this->bSuspendNpcs = true;
}


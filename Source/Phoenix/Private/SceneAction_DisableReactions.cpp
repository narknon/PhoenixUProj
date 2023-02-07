#include "SceneAction_DisableReactions.h"

USceneAction_DisableReactions::USceneAction_DisableReactions() {
    this->Priority = EStandardManagedPriority::ActiveCinematic;
    this->PriorityNew = ECharacterShutdownPriority::InCinematic;
}


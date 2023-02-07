#pragma once
#include "CoreMinimal.h"
#include "ESceneRigCategory.generated.h"

UENUM()
enum class ESceneRigCategory : int8 {
    None,
    Cinematic,
    Conversation,
    ConversationAmbient,
    Station,
    GhostStory,
    Weather,
    Vignette,
    DialogueOnly,
    Mission,
    WowMoment,
    PIM,
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigStoryState.generated.h"

UENUM(BlueprintType)
enum SceneRigStoryState {
    STORY_NEW,
    STORY_QUEUED,
    STORY_MARKED_FOR_TRANSITION,
    STORY_TRANSITIONING_OUT,
    STORY_ACTIVE,
    STORY_READY_TO_TRANSITION,
    STORY_ENDED,
    STORY_DELETE,
    STORY_STATE_COUNT,
    STORY_MAX UMETA(Hidden),
};


#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphActorState.generated.h"

UENUM(BlueprintType)
enum class EStoryGraphActorState : uint8 {
    StoryNotStarted,
    StoryReadyToStart,
    StoryPlaying,
    StoryFinished,
};


#pragma once
#include "CoreMinimal.h"
#include "StoryParticipantState.generated.h"

UENUM(BlueprintType)
enum StoryParticipantState {
    PARTICIPANT_ADDED,
    PARTICIPANT_ARRIVED,
    PARTICIPANT_ENTERED,
    PARTICIPANT_EXITING,
    PARTICIPANT_KICKED,
    PARTICIPANT_EXITED,
    PARTICIPANT_MAX UMETA(Hidden),
};


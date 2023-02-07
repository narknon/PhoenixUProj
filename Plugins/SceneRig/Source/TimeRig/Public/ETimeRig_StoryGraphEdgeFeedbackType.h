#pragma once
#include "CoreMinimal.h"
#include "ETimeRig_StoryGraphEdgeFeedbackType.generated.h"

UENUM(BlueprintType)
enum class ETimeRig_StoryGraphEdgeFeedbackType : uint8 {
    NoFeedback,
    FeedbackStopOnTargetStart,
    FeedbackEventOnTargetStart,
    ETimeRig_MAX UMETA(Hidden),
};


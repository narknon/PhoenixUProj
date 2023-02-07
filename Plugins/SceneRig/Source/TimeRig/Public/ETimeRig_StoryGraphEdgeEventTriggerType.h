#pragma once
#include "CoreMinimal.h"
#include "ETimeRig_StoryGraphEdgeEventTriggerType.generated.h"

UENUM(BlueprintType)
enum class ETimeRig_StoryGraphEdgeEventTriggerType : uint8 {
    TriggerEvent,
    DoNotTriggerEvent,
    ETimeRig_MAX UMETA(Hidden),
};


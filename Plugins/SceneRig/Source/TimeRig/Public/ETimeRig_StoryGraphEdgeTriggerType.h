#pragma once
#include "CoreMinimal.h"
#include "ETimeRig_StoryGraphEdgeTriggerType.generated.h"

UENUM(BlueprintType)
enum class ETimeRig_StoryGraphEdgeTriggerType : uint8 {
    TriggeredByFinish,
    TriggeredByParentNode,
    TriggeredByEvent,
    DoNotTrigger,
    ETimeRig_MAX UMETA(Hidden),
};


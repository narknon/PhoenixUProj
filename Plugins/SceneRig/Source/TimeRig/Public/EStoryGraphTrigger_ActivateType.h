#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphTrigger_ActivateType.generated.h"

UENUM(BlueprintType)
enum class EStoryGraphTrigger_ActivateType : uint8 {
    ActivatedByFinish,
    ActivatedByEvent,
    EStoryGraphTrigger_MAX UMETA(Hidden),
};


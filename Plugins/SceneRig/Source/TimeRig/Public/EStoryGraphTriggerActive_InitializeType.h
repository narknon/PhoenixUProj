#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphTriggerActive_InitializeType.generated.h"

UENUM(BlueprintType)
enum class EStoryGraphTriggerActive_InitializeType : uint8 {
    InitializeWhenTriggered,
    InitializeWithPrevious,
    EStoryGraphTriggerActive_MAX UMETA(Hidden),
};


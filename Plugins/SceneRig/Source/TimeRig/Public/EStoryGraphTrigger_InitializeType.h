#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphTrigger_InitializeType.generated.h"

UENUM(BlueprintType)
enum class EStoryGraphTrigger_InitializeType : uint8 {
    InitializeWithPrevious,
    InitializeByEvent,
    EStoryGraphTrigger_MAX UMETA(Hidden),
};


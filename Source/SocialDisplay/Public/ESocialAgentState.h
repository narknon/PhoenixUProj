#pragma once
#include "CoreMinimal.h"
#include "ESocialAgentState.generated.h"

UENUM(BlueprintType)
enum class ESocialAgentState : uint8 {
    Inactive,
    Blocking,
    Avoiding,
};


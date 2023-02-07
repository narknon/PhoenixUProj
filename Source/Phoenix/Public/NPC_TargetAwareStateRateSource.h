#pragma once
#include "CoreMinimal.h"
#include "NPC_TargetAwareStateRateSource.generated.h"

UENUM(BlueprintType)
enum class NPC_TargetAwareStateRateSource : uint8 {
    EnterAware,
    ExitAware,
    EnterAlert,
    ExitAlert,
    NPC_MAX UMETA(Hidden),
};


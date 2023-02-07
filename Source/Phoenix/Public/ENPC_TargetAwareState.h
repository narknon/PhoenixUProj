#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetAwareState.generated.h"

UENUM(BlueprintType)
enum class ENPC_TargetAwareState : uint8 {
    None,
    Unaware,
    Aware,
    Alert,
    Attack,
    ENPC_MAX UMETA(Hidden),
};


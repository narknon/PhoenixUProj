#pragma once
#include "CoreMinimal.h"
#include "ENPC_EvadeMobilityType.generated.h"

UENUM(BlueprintType)
enum class ENPC_EvadeMobilityType : uint8 {
    None,
    Slow,
    Medium,
    Fast,
    Count,
    ENPC_MAX UMETA(Hidden),
};


#pragma once
#include "CoreMinimal.h"
#include "EOdcPenaltyTableMode.generated.h"

UENUM(BlueprintType)
enum class EOdcPenaltyTableMode : uint8 {
    PENALTY_MODE_DISABLED,
    PENALTY_MODE_MAX UMETA(Hidden),
    PENALTY_MODE_TOTAL,
};


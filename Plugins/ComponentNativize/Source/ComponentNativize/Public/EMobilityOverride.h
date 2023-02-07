#pragma once
#include "CoreMinimal.h"
#include "EMobilityOverride.generated.h"

UENUM(BlueprintType)
enum class EMobilityOverride : uint8 {
    MO_NONE,
    MO_STATIC,
    MO_STATIONARY,
    MO_MOVEABLE,
    MO_MAX UMETA(Hidden),
};


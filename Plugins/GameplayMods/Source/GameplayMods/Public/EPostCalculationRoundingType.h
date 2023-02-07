#pragma once
#include "CoreMinimal.h"
#include "EPostCalculationRoundingType.generated.h"

UENUM(BlueprintType)
enum class EPostCalculationRoundingType : uint8 {
    RoundToNearest,
    TowardsZero,
    AwayFromZero,
};


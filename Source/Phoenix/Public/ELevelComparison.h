#pragma once
#include "CoreMinimal.h"
#include "ELevelComparison.generated.h"

UENUM(BlueprintType)
enum class ELevelComparison : uint8 {
    None,
    MinimumDifference,
    MaximumDifference,
    WithinRangedOf,
    OutsideRangeOf,
};


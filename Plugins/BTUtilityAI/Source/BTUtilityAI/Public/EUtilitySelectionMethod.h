#pragma once
#include "CoreMinimal.h"
#include "EUtilitySelectionMethod.generated.h"

UENUM(BlueprintType)
enum class EUtilitySelectionMethod : uint8 {
    FirstScore,
    HighestScore,
    WeightedRandom,
};


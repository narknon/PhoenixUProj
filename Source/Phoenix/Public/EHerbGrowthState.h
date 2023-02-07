#pragma once
#include "CoreMinimal.h"
#include "EHerbGrowthState.generated.h"

UENUM(BlueprintType)
enum class EHerbGrowthState : uint8 {
    None,
    Growing,
    Grown,
    Harvested,
    Regrowing,
};


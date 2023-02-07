#pragma once
#include "CoreMinimal.h"
#include "EPostDeathSortingMode.generated.h"

UENUM(BlueprintType)
enum class EPostDeathSortingMode : uint8 {
    FirstInFirstOut,
    ClosestToPlayerFirst,
    FarthestFromPlayerFirst,
    None,
};


#pragma once
#include "CoreMinimal.h"
#include "ELevelBoundsBestHeuristic.generated.h"

UENUM(BlueprintType)
enum class ELevelBoundsBestHeuristic : uint8 {
    SmallestVolume,
    LargestVolume,
    ClosestDistance,
    FarthestDistance,
    SmallestAreaXY,
    LargestAreaXY,
    First,
    Oldest,
    Youngest,
};


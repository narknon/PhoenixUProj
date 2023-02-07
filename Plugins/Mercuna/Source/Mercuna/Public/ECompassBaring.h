#pragma once
#include "CoreMinimal.h"
#include "ECompassBaring.generated.h"

UENUM(BlueprintType)
enum class ECompassBaring : uint8 {
    West_MinX,
    East_MaxX,
    North_MinY,
    South_MaxY,
    Max,
};


#pragma once
#include "CoreMinimal.h"
#include "EWindDirectionCompass.generated.h"

UENUM(BlueprintType)
enum class EWindDirectionCompass : uint8 {
    North,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    NorthWest,
};


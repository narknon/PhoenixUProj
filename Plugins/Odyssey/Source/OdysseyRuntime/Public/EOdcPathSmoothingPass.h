#pragma once
#include "CoreMinimal.h"
#include "EOdcPathSmoothingPass.generated.h"

UENUM(BlueprintType)
enum class EOdcPathSmoothingPass : uint8 {
    Original,
    FilterSignificantPoints,
    Extrude,
    AlignPointsOnSlopes,
    Smoothed,
};


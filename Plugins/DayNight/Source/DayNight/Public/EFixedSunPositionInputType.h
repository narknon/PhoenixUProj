#pragma once
#include "CoreMinimal.h"
#include "EFixedSunPositionInputType.generated.h"

UENUM(BlueprintType)
enum class EFixedSunPositionInputType : uint8 {
    AltitudeDegrees,
    PercentageOfTransit,
    PercentageOfTransitOrMidnight,
};


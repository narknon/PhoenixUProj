#pragma once
#include "CoreMinimal.h"
#include "ETutorialPosition.generated.h"

UENUM(BlueprintType)
enum class ETutorialPosition : uint8 {
    Tutorial_TopLeft,
    Tutorial_TopCenter,
    Tutorial_TopRight,
    Tutorial_MiddleLeft,
    Tutorial_MiddleCenter,
    Tutorial_MiddleRight,
    Tutorial_BottomLeft,
    Tutorial_BottomCenter,
    Tutorial_BottomRight,
    Tutorial_CustomLocation,
    Tutorial_MAX UMETA(Hidden),
};


#pragma once
#include "CoreMinimal.h"
#include "EPerformTaskSplineTypes.generated.h"

UENUM(BlueprintType)
enum class EPerformTaskSplineTypes : uint8 {
    SlowWalk,
    Walk,
    Jog,
};


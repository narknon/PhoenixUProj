#pragma once
#include "CoreMinimal.h"
#include "ECameraStackAnimationSelection.generated.h"

UENUM(BlueprintType)
enum class ECameraStackAnimationSelection : uint8 {
    Random,
    ClosestToCameraRotation,
    LeftOrRight,
};


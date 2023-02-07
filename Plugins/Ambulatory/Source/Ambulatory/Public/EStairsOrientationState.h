#pragma once
#include "CoreMinimal.h"
#include "EStairsOrientationState.generated.h"

UENUM(BlueprintType)
enum class EStairsOrientationState : uint8 {
    None,
    StairsLeft,
    StairsRight,
};


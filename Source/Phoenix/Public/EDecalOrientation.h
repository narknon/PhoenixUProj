#pragma once
#include "CoreMinimal.h"
#include "EDecalOrientation.generated.h"

UENUM(BlueprintType)
enum class EDecalOrientation : uint8 {
    Random,
    Zero,
    InstigatorToTarget,
    TargetToInstigator,
};


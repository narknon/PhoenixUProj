#pragma once
#include "CoreMinimal.h"
#include "EWaterType.generated.h"

UENUM(BlueprintType)
enum class EWaterType : uint8 {
    NoWater,
    Shallow,
    Deep,
};


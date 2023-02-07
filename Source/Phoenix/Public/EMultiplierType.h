#pragma once
#include "CoreMinimal.h"
#include "EMultiplierType.generated.h"

UENUM(BlueprintType)
enum class EMultiplierType : uint8 {
    MultiplyByAxis,
    MultiplyByValue,
    MultiplyByCustomValue,
};


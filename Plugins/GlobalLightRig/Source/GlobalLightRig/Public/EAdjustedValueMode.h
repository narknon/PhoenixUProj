#pragma once
#include "CoreMinimal.h"
#include "EAdjustedValueMode.generated.h"

UENUM(BlueprintType)
enum class EAdjustedValueMode : uint8 {
    NoChange,
    Set,
    Multiply,
    Add,
    Subtract,
    Divide,
    Percent,
    ClampOriginal,
};


#pragma once
#include "CoreMinimal.h"
#include "EPropModCalculationType.generated.h"

UENUM(BlueprintType)
enum class EPropModCalculationType : uint8 {
    Maximum,
    Minimum,
    PreAdd,
    FactorIncrease,
    Multiply,
    PostAdd,
    Count,
};


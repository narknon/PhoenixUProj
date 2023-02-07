#pragma once
#include "CoreMinimal.h"
#include "EInteractUseTargetAxis.generated.h"

UENUM(BlueprintType)
enum class EInteractUseTargetAxis : uint8 {
    XAxis,
    YAxis,
    ZAxis,
    NegXAxis,
    NegYAxis,
    NegZAxis,
};


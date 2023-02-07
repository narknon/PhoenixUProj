#pragma once
#include "CoreMinimal.h"
#include "ETransformFunction.generated.h"

UENUM(BlueprintType)
enum class ETransformFunction : uint8 {
    NoTransformFunction,
    TransformLinear,
    TransformSine,
};


#pragma once
#include "CoreMinimal.h"
#include "ESkinFXFunctionModOp.generated.h"

UENUM(BlueprintType)
enum class ESkinFXFunctionModOp : uint8 {
    Add,
    Subtract,
    Multiply,
    Divide,
    Mod,
    Power,
    Min,
    Max,
};


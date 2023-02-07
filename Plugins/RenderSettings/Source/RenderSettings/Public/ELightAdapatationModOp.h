#pragma once
#include "CoreMinimal.h"
#include "ELightAdapatationModOp.generated.h"

UENUM(BlueprintType)
enum class ELightAdapatationModOp : uint8 {
    Set,
    Multiply,
    Divide,
    Add,
    Subtract,
    Min,
    Max,
};


#pragma once
#include "CoreMinimal.h"
#include "ELightAdapatationEVModOp.generated.h"

UENUM(BlueprintType)
enum class ELightAdapatationEVModOp : uint8 {
    Set,
    Add,
    Subtract,
    Min,
    Max,
};


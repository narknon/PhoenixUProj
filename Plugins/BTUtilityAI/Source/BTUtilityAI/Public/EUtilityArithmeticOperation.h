#pragma once
#include "CoreMinimal.h"
#include "EUtilityArithmeticOperation.generated.h"

UENUM(BlueprintType)
enum class EUtilityArithmeticOperation : uint8 {
    Equal,
    NotEqual,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
};


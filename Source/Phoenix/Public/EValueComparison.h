#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.generated.h"

UENUM(BlueprintType)
enum class EValueComparison : uint8 {
    Less,
    LessEqual,
    Equal,
    GreaterEqual,
    Greater,
    NotEqual,
};


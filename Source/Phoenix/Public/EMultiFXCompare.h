#pragma once
#include "CoreMinimal.h"
#include "EMultiFXCompare.generated.h"

UENUM(BlueprintType)
enum class EMultiFXCompare : uint8 {
    Equal,
    NotEqual,
    GreatherThan,
    GreaterThanEqual,
    LessThan,
    LessThanEqual,
};


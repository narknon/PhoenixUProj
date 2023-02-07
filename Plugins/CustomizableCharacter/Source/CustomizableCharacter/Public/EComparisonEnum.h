#pragma once
#include "CoreMinimal.h"
#include "EComparisonEnum.generated.h"

UENUM(BlueprintType)
enum class EComparisonEnum : uint8 {
    COMP_EQUAL,
    COMP_NOTEQUAL,
    COMP_MAX UMETA(Hidden),
};


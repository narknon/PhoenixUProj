#pragma once
#include "CoreMinimal.h"
#include "EStolenType.generated.h"

UENUM(BlueprintType)
enum class EStolenType : uint8 {
    STOLEN_TYPE_DONT_CARE,
    STOLEN_TYPE_STOLEN,
    STOLEN_TYPE_NOT_STOLEN,
    STOLEN_TYPE_MAX UMETA(Hidden),
};


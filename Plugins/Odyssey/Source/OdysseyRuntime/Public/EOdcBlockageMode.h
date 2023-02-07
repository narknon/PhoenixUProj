#pragma once
#include "CoreMinimal.h"
#include "EOdcBlockageMode.generated.h"

UENUM(BlueprintType)
enum class EOdcBlockageMode : uint8 {
    BLOCKED_IF_ANY_MATCH,
    BLOCKED_IF_ALL_MATCH,
    BLOCKED_IF_MAX UMETA(Hidden),
};


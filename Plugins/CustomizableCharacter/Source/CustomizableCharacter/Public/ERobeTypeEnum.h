#pragma once
#include "CoreMinimal.h"
#include "ERobeTypeEnum.generated.h"

UENUM(BlueprintType)
enum class ERobeTypeEnum : uint8 {
    ROBE_TYPE_A,
    ROBE_TYPE_B,
    ROBE_TYPE_C,
    ROBE_TYPE_MAX UMETA(Hidden),
};


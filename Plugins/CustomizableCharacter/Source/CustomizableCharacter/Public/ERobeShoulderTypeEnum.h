#pragma once
#include "CoreMinimal.h"
#include "ERobeShoulderTypeEnum.generated.h"

UENUM(BlueprintType)
enum class ERobeShoulderTypeEnum : uint8 {
    ROBE_SHOULDER_TYPE_BULKY,
    ROBE_SHOULDER_TYPE_SNUG,
    ROBE_SHOULDER_TYPE_MAX UMETA(Hidden),
};


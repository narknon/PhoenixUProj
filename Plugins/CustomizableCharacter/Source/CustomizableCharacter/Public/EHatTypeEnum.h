#pragma once
#include "CoreMinimal.h"
#include "EHatTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EHatTypeEnum : uint8 {
    HAT_TYPE_A,
    HAT_TYPE_B,
    HAT_TYPE_C,
    HAT_TYPE_D,
    HAT_TYPE_E,
    HAT_TYPE_MAX UMETA(Hidden),
};


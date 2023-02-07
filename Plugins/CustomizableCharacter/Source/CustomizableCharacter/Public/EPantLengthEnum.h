#pragma once
#include "CoreMinimal.h"
#include "EPantLengthEnum.generated.h"

UENUM(BlueprintType)
enum class EPantLengthEnum : uint8 {
    PANT_LENGTH_DRESS,
    PANT_LENGTH_THIGH,
    PANT_LENGTH_KNEE,
    PANT_LENGTH_KNICKER,
    PANT_LENGTH_CALF,
    PANT_LENGTH_SHIN,
    PANT_LENGTH_SHOE,
    PANT_LENGTH_MAX UMETA(Hidden),
};


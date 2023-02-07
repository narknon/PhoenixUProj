#pragma once
#include "CoreMinimal.h"
#include "EShoeHeightEnum.generated.h"

UENUM(BlueprintType)
enum class EShoeHeightEnum : uint8 {
    SHOE_HEIGHT_THIGH,
    SHOE_HEIGHT_KNEE,
    SHOE_HEIGHT_KNICKER,
    SHOE_HEIGHT_CALF,
    SHOE_HEIGHT_SHIN,
    SHOE_HEIGHT_SHOE,
    SHOE_HEIGHT_SLIPPER,
    SHOE_HEIGHT_MAX UMETA(Hidden),
};


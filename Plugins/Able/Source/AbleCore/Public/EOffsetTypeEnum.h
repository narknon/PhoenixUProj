#pragma once
#include "CoreMinimal.h"
#include "EOffsetTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EOffsetTypeEnum : uint8 {
    OFFSETTYPE_SECONDS,
    OFFSETTYPE_PERCENT,
    OFFSETTYPE_FRAMES,
    OFFSETTYPE_MAX UMETA(Hidden),
};


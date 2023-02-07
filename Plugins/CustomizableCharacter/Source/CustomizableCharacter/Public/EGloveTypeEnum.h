#pragma once
#include "CoreMinimal.h"
#include "EGloveTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EGloveTypeEnum : uint8 {
    GLOVE_TYPE_NORMAL,
    GLOVE_TYPE_FINGERLESS,
    GLOVE_TYPE_MAX UMETA(Hidden),
};


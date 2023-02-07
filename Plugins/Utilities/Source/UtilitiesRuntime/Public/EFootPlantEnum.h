#pragma once
#include "CoreMinimal.h"
#include "EFootPlantEnum.generated.h"

UENUM(BlueprintType)
enum class EFootPlantEnum : uint8 {
    FOOTPLANT_NONE,
    FOOTPLANT_LEFT,
    FOOTPLANT_RIGHT,
    FOOTPLANT_BOTH,
    FOOTPLANT_UNAVAILABLE,
    FOOTPLANT_MAX UMETA(Hidden),
};


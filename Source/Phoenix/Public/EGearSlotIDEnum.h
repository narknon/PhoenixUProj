#pragma once
#include "CoreMinimal.h"
#include "EGearSlotIDEnum.generated.h"

UENUM(BlueprintType)
enum class EGearSlotIDEnum : uint8 {
    HEAD,
    OUTFIT,
    BACK,
    NECK,
    HAND,
    FACE,
    Num,
};


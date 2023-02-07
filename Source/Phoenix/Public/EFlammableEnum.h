#pragma once
#include "CoreMinimal.h"
#include "EFlammableEnum.generated.h"

UENUM(BlueprintType)
enum class EFlammableEnum : uint8 {
    FE_INFLAMMABLE,
    FE_FLAMMABLE,
    FE_USE_MPD,
    FE_MAX UMETA(Hidden),
};


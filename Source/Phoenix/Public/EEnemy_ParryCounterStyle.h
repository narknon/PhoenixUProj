#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryCounterStyle.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryCounterStyle : uint8 {
    Default,
    Direct,
    Downward,
    Upward,
    EEnemy_MAX UMETA(Hidden),
};


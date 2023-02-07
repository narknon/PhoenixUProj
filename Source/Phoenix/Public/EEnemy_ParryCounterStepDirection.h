#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryCounterStepDirection.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryCounterStepDirection : uint8 {
    Default,
    Forwards,
    Backwards,
    EEnemy_MAX UMETA(Hidden),
};


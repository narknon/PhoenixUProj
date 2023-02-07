#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryCounterType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryCounterType : uint8 {
    Default,
    None,
    EEnemy_MAX UMETA(Hidden),
};


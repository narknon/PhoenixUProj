#pragma once
#include "CoreMinimal.h"
#include "EEnemy_InitTreeTimeoutAction.generated.h"

UENUM(BlueprintType)
enum class EEnemy_InitTreeTimeoutAction : uint8 {
    FailNoEnter,
    EnterWithReset,
    EnterNoReset,
    EEnemy_MAX UMETA(Hidden),
};


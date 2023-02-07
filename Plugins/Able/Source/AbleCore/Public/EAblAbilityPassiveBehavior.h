#pragma once
#include "CoreMinimal.h"
#include "EAblAbilityPassiveBehavior.generated.h"

UENUM(BlueprintType)
enum class EAblAbilityPassiveBehavior : uint8 {
    CannotBePassive,
    RefreshDuration,
    IncreaseStackCount,
    IncreaseAndRefresh,
};


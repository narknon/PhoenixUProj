#pragma once
#include "CoreMinimal.h"
#include "EPostDeathCleanupMode.generated.h"

UENUM(BlueprintType)
enum class EPostDeathCleanupMode : uint8 {
    TriggerOnMaximumReached,
    TriggerOnTimer,
    None,
};


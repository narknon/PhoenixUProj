#pragma once
#include "CoreMinimal.h"
#include "EStandardManagedPriority.generated.h"

UENUM(BlueprintType)
enum class EStandardManagedPriority : uint8 {
    Lowest,
    AblAbility,
    NPC,
    Teleport,
    PassiveCinematic,
    ActiveCinematic,
    Highest,
    Debug,
};


#pragma once
#include "CoreMinimal.h"
#include "EManagedMovementModePriority.generated.h"

UENUM(BlueprintType)
enum class EManagedMovementModePriority : uint8 {
    Lowest,
    PassiveCinematic,
    ActiveCinematic,
    Highest,
};


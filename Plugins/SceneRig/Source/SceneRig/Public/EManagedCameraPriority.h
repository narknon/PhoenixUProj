#pragma once
#include "CoreMinimal.h"
#include "EManagedCameraPriority.generated.h"

UENUM(BlueprintType)
enum class EManagedCameraPriority : uint8 {
    Lowest,
    PassiveCinematic,
    ActiveCinematic,
    Highest,
};


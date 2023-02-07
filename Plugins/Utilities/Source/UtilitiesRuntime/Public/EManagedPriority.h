#pragma once
#include "CoreMinimal.h"
#include "EManagedPriority.generated.h"

UENUM(BlueprintType)
enum class EManagedPriority : uint8 {
    Lowest,
    System,
    AmbientBehavior,
    DynamicBehavior,
    BackgroundCinematic,
    ForegroundCinematic,
    Highest,
};


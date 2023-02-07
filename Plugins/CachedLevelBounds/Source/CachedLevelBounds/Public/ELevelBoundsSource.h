#pragma once
#include "CoreMinimal.h"
#include "ELevelBoundsSource.generated.h"

UENUM(BlueprintType)
enum class ELevelBoundsSource : uint8 {
    Actors,
    Landscape,
    AllowUnloaded,
};


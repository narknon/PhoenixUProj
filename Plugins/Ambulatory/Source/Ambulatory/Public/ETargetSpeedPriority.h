#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedPriority.generated.h"

UENUM(BlueprintType)
namespace ETargetSpeedPriority {
    enum Type {
        None,
        LowestPriority,
        FromWaterVolume,
        FromMechanic,
        FromReaction,
        FromTrigger,
        HighestPriority,
    };
}


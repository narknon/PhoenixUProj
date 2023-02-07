#pragma once
#include "CoreMinimal.h"
#include "EHeadTrackingPriority.generated.h"

UENUM(BlueprintType)
namespace EHeadTrackingPriority {
    enum Type {
        None,
        LowestPriority,
        UpperBodyAlert,
        FullBodyUsage,
        FullBodySpecialUsage,
        UpperBodyUsage,
        UpperBodySpecialUsage,
        Cinematic,
        HighestPriority,
    };
}


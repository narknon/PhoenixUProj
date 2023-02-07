#pragma once
#include "CoreMinimal.h"
#include "ELeftArmPriority.generated.h"

UENUM(BlueprintType)
namespace ELeftArmPriority {
    enum Type {
        None,
        LowestPriority,
        UpperBodyIdle,
        UpperBodyFlourish,
        FullBodyUsage,
        UpperBodyUsage,
        Cinematic,
        HighestPriority,
    };
}


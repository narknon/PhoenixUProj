#pragma once
#include "CoreMinimal.h"
#include "ECombatAdditivePriority.generated.h"

UENUM(BlueprintType)
namespace ECombatAdditivePriority {
    enum Type {
        None,
        LowestPriority,
        UpperBodyIdle,
        FullBodyUsage,
        UpperBodyUsage,
        Cinematic,
        HighestPriority,
    };
}


#pragma once
#include "CoreMinimal.h"
#include "EDisbandPriority.generated.h"

UENUM(BlueprintType)
enum class EDisbandPriority : uint8 {
    LowestPriority,
    PathUpdatePriority,
    JoinFailurePriority,
    ForcedRemovePriority,
    RemoveSplinePriority,
};


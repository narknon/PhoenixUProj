#pragma once
#include "CoreMinimal.h"
#include "EPhysicalReactionTaskAction.generated.h"

UENUM(BlueprintType)
enum class EPhysicalReactionTaskAction : uint8 {
    StartImpactReaction,
    StartReaction,
    HoverStart,
    HoverEnd,
    NoAction,
};


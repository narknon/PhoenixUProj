#pragma once
#include "CoreMinimal.h"
#include "EEnemy_TagContainer.generated.h"

UENUM(BlueprintType)
enum class EEnemy_TagContainer : uint8 {
    Shuffle,
    Taunt,
    Spawn,
    IdleBreak,
    Flourish,
    None,
    BecomeAware,
    JumpSpline,
    Count,
    EEnemy_MAX UMETA(Hidden),
};


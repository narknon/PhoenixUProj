#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetSelectionScore.generated.h"

UENUM(BlueprintType)
enum class ENPC_TargetSelectionScore : uint8 {
    Distance,
    MaintainTarget,
    StayIn,
    CognitionPriority,
    LargeCharacter,
    NumAttacking,
    RecentlyAttackedBy,
    RecentlyAttackedByPlayer,
    HighlightedByPlayer,
    Attacking,
    RecentlyAttackedPlayer,
    RecentlyAttackedTarget,
    Reacting,
    InCCReaction,
    InRagDoll,
    InAir,
    InCriticalHealth,
    InNearDeathKneeling,
    ShieldsOn,
    Level,
    Health,
    Threat,
    SpiderOnFire,
    InferiusOnFire,
    InferiusKamikaze,
    Leader,
    Perk,
    IneligibleToChange,
    Count,
    ENPC_MAX UMETA(Hidden),
};


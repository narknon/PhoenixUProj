#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingKillEventType.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingKillEventType : uint8 {
    None,
    HitKillBox,
    HitTarget,
    Poof,
    StartBurrow,
};


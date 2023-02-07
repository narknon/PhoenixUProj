#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIDodgeState.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIDodgeState : uint8 {
    None,
    DodgeLeft,
    DodgeRight,
    RollLeft,
    RollRight,
    SlideLeft,
    SlideRight,
    Duck,
    ApparateToLocation,
};


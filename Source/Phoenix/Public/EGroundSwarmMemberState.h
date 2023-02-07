#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmMemberState.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmMemberState : uint8 {
    Frozen,
    Freefalling,
    OnSurface,
    Burrowing,
    DeathLeap,
    Dead,
};


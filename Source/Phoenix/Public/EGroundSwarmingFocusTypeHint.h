#pragma once
#include "CoreMinimal.h"
#include "EGroundSwarmingFocusTypeHint.generated.h"

UENUM(BlueprintType)
enum class EGroundSwarmingFocusTypeHint : uint8 {
    None,
    Swarm,
    Target,
    Player,
};


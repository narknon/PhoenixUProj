#pragma once
#include "CoreMinimal.h"
#include "ENpcReactFlyToLocationOption.generated.h"

UENUM(BlueprintType)
enum class ENpcReactFlyToLocationOption : uint8 {
    ReactionInstigatorLocation,
    ReactionTargetLocation,
};


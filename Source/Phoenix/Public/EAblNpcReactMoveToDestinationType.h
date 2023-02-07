#pragma once
#include "CoreMinimal.h"
#include "EAblNpcReactMoveToDestinationType.generated.h"

UENUM(BlueprintType)
enum class EAblNpcReactMoveToDestinationType : uint8 {
    CustomGlobal,
    CustomLocal,
    ReactionTargetLocation,
    ReactionInstigator,
};


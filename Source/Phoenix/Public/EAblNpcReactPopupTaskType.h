#pragma once
#include "CoreMinimal.h"
#include "EAblNpcReactPopupTaskType.generated.h"

UENUM(BlueprintType)
enum class EAblNpcReactPopupTaskType : uint8 {
    ReactionInitialVelocity,
    ReactionInitialDirection,
    DirectionToInstigator,
    ImpactDirection,
    DirectionToTargetActor,
};


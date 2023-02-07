#pragma once
#include "CoreMinimal.h"
#include "EAblNpcReactMoveToSpeedType.generated.h"

UENUM(BlueprintType)
enum class EAblNpcReactMoveToSpeedType : uint8 {
    Custom,
    ReactionVelocityMagnitude,
    TimeCurve,
    DistancetoDestinationCurve,
    PositionCurve,
};


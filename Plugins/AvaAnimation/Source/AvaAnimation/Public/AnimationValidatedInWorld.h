#pragma once
#include "CoreMinimal.h"
#include "AnimationValidatedInWorld.generated.h"

UENUM(BlueprintType)
enum AnimationValidatedInWorld {
    INWORLD_UNTESTED,
    INWORLD_OBSTRUCTED,
    INWORLD_VALIDATED,
    INWORLD_MAX UMETA(Hidden),
};


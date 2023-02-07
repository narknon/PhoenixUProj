#pragma once
#include "CoreMinimal.h"
#include "EMap3DState.generated.h"

UENUM(BlueprintType)
enum class EMap3DState : uint8 {
    IDLE,
    START,
    DISCOVER,
    TRANSITION_TO_GROUP,
    GROUP,
    TRANSITION_TO_SINGLE,
    SINGLE,
    TRANSITION_TO_CASTLE,
    CASTLE,
    FASTTRAVEL,
};


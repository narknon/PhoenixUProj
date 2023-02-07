#pragma once
#include "CoreMinimal.h"
#include "EMobilityActionState.generated.h"

UENUM(BlueprintType)
namespace EMobilityActionState {
    enum Type {
        IsIdle,
        IsWalking,
        IsJogging,
        IsSprinting,
        IsJumping,
        IsFalling,
        IsSideStepping,
    };
}


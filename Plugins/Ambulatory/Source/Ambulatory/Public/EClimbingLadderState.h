#pragma once
#include "CoreMinimal.h"
#include "EClimbingLadderState.generated.h"

UENUM(BlueprintType)
namespace EClimbingLadderState {
    enum Type {
        None,
        Mount,
        MountDown,
        ClimbingLadder,
        DescendingLadder,
        Paused,
        DismountTop,
        DismountBottom,
        MountJump,
    };
}


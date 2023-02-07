#pragma once
#include "CoreMinimal.h"
#include "ESBlockedByWallAnimState.generated.h"

UENUM(BlueprintType)
namespace ESBlockedByWallAnimState {
    enum Type {
        None,
        BothHandsOut,
        RightHandOut,
        LeftHandOut,
    };
}


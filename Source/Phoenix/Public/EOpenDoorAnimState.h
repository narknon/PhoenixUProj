#pragma once
#include "CoreMinimal.h"
#include "EOpenDoorAnimState.generated.h"

UENUM(BlueprintType)
namespace EOpenDoorAnimState {
    enum Type {
        LeftHand,
        RightHand,
        BothHands,
    };
}


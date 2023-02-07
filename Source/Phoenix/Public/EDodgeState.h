#pragma once
#include "CoreMinimal.h"
#include "EDodgeState.generated.h"

UENUM(BlueprintType)
namespace EDodgeState {
    enum Type {
        None,
        DodgeForward,
        DodgeLeft,
        DodgeRight,
        DodgeBackward,
    };
}


#pragma once
#include "CoreMinimal.h"
#include "EParryState.generated.h"

UENUM(BlueprintType)
namespace EParryState {
    enum Type {
        None,
        Swipe1,
        Swipe2,
        RightToLeft_Down,
        LeftToRight_Up,
        RightToLeft_Up,
        LeftToRight_Down,
    };
}


#pragma once
#include "CoreMinimal.h"
#include "ELastWandCastState.generated.h"

UENUM(BlueprintType)
namespace ELastWandCastState {
    enum Type {
        None,
        Base,
        FromLeft,
        FromRight,
        Transition,
        LeftFoot,
        LeftFoot_Transition,
    };
}


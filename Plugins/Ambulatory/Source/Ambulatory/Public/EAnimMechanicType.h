#pragma once
#include "CoreMinimal.h"
#include "EAnimMechanicType.generated.h"

UENUM(BlueprintType)
namespace EAnimMechanicType {
    enum Type {
        Undetermined,
        Idle,
        TurnStart,
        MoveFwdLoop,
        TurnStop,
        Pivot,
        ShortStep,
        TurnInPlace,
        StrafeStart,
        StrafeLoop,
        StrafeStop,
        Jump,
        Land,
    };
}


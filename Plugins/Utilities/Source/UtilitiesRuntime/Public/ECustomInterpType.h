#pragma once
#include "CoreMinimal.h"
#include "ECustomInterpType.generated.h"

UENUM(BlueprintType)
namespace ECustomInterpType {
    enum Type {
        None,
        Constant,
        Interp,
        EaseIn,
        EaseOut,
        EaseInOut,
    };
}


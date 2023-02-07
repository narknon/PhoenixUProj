#pragma once
#include "CoreMinimal.h"
#include "EPreWandCastState.generated.h"

UENUM(BlueprintType)
namespace EPreWandCastState {
    enum Type {
        None,
        FromLeft,
        FromRight,
    };
}


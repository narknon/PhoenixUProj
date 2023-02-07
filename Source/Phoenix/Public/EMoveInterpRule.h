#pragma once
#include "CoreMinimal.h"
#include "EMoveInterpRule.generated.h"

UENUM(BlueprintType)
namespace EMoveInterpRule {
    enum Type {
        NoInterp,
        Interp,
        InterpConstant,
    };
}


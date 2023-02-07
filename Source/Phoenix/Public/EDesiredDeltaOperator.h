#pragma once
#include "CoreMinimal.h"
#include "EDesiredDeltaOperator.generated.h"

UENUM(BlueprintType)
namespace EDesiredDeltaOperator {
    enum Type {
        And,
        Or,
        StrafeRules,
    };
}


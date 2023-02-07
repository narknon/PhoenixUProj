#pragma once
#include "CoreMinimal.h"
#include "EStairsDirectionState.generated.h"

UENUM(BlueprintType)
namespace EStairsDirectionState {
    enum Type {
        None,
        GoingDown,
        GoingUp,
    };
}


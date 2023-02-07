#pragma once
#include "CoreMinimal.h"
#include "EStairsState.generated.h"

UENUM(BlueprintType)
namespace EStairsState {
    enum Type {
        None,
        OnStairs,
        OnSlopes,
    };
}


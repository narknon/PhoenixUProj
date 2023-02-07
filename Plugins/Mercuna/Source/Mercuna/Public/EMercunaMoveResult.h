#pragma once
#include "CoreMinimal.h"
#include "EMercunaMoveResult.generated.h"

UENUM(BlueprintType)
namespace EMercunaMoveResult {
    enum Type {
        Success,
        Failed,
        Cancelled,
        Blocked,
        Invalid,
    };
}


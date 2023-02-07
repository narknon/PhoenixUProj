#pragma once
#include "CoreMinimal.h"
#include "E_Goal.generated.h"

UENUM(BlueprintType)
namespace E_Goal {
    enum Type {
        None,
        Current,
        Future,
        E_MAX UMETA(Hidden),
    };
}


#pragma once
#include "CoreMinimal.h"
#include "EContextTaskOperationType.generated.h"

UENUM(BlueprintType)
namespace EContextTaskOperationType {
    enum Type {
        SetAndClear,
        ClearAndSet,
        Set,
        Clear,
    };
}


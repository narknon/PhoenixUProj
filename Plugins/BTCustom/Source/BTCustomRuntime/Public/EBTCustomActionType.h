#pragma once
#include "CoreMinimal.h"
#include "EBTCustomActionType.generated.h"

UENUM(BlueprintType)
namespace EBTCustomActionType {
    enum Type {
        Started,
        Completed,
        Canceled,
    };
}


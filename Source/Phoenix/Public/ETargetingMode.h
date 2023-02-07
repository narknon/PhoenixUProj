#pragma once
#include "CoreMinimal.h"
#include "ETargetingMode.generated.h"

UENUM(BlueprintType)
namespace ETargetingMode {
    enum Type {
        None,
        AutoTarget,
        LockOn,
    };
}


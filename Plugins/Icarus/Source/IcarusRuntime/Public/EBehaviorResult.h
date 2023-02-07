#pragma once
#include "CoreMinimal.h"
#include "EBehaviorResult.generated.h"

UENUM(BlueprintType)
namespace EBehaviorResult {
    enum Type {
        Success,
        Failed,
    };
}


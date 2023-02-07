#pragma once
#include "CoreMinimal.h"
#include "ETimeDilationTarget.generated.h"

UENUM(BlueprintType)
namespace ETimeDilationTarget {
    enum Type {
        World,
        Self,
        Owner,
        Instigator,
        TargetActor,
    };
}


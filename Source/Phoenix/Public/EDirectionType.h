#pragma once
#include "CoreMinimal.h"
#include "EDirectionType.generated.h"

UENUM(BlueprintType)
namespace EDirectionType {
    enum Type {
        ImpactDirection,
        CalculatedWorldDirection,
    };
}


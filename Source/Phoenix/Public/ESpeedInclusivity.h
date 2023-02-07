#pragma once
#include "CoreMinimal.h"
#include "ESpeedInclusivity.generated.h"

UENUM(BlueprintType)
namespace ESpeedInclusivity {
    enum Type {
        Inclusive,
        InclusiveMinOnly,
        InclusiveMaxOnly,
        NotInclusive,
    };
}


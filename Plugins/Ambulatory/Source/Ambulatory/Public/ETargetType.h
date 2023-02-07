#pragma once
#include "CoreMinimal.h"
#include "ETargetType.generated.h"

UENUM(BlueprintType)
namespace ETargetType {
    enum Type {
        None,
        Actor,
        Location,
        Camera,
        DesiredDirection,
        StaticDirection,
        Custom,
    };
}


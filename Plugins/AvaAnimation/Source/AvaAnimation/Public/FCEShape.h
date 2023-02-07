#pragma once
#include "CoreMinimal.h"
#include "FCEShape.generated.h"

UENUM(BlueprintType)
namespace FCEShape {
    enum Type {
        Line,
        Box,
        Sphere,
        Capsule,
    };
}


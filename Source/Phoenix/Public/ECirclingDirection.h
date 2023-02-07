#pragma once
#include "CoreMinimal.h"
#include "ECirclingDirection.generated.h"

UENUM(BlueprintType)
enum class ECirclingDirection : uint8 {
    Clockwise,
    Anticlockwise,
    Random,
    Closest,
};


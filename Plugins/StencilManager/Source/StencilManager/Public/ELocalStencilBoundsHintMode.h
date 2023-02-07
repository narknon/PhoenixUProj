#pragma once
#include "CoreMinimal.h"
#include "ELocalStencilBoundsHintMode.generated.h"

UENUM(BlueprintType)
enum class ELocalStencilBoundsHintMode : uint8 {
    Override,
    Maximum,
    Minimum,
};


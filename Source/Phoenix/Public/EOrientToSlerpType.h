#pragma once
#include "CoreMinimal.h"
#include "EOrientToSlerpType.generated.h"

UENUM(BlueprintType)
enum class EOrientToSlerpType : uint8 {
    Snap,
    Velocity,
    Filter,
    Freeze,
};


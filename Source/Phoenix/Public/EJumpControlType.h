#pragma once
#include "CoreMinimal.h"
#include "EJumpControlType.generated.h"

UENUM(BlueprintType)
enum class EJumpControlType : uint8 {
    Velocity,
    Speed,
};


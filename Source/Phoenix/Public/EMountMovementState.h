#pragma once
#include "CoreMinimal.h"
#include "EMountMovementState.generated.h"

UENUM(BlueprintType)
enum class EMountMovementState : uint8 {
    Ground,
    Flying,
    Takeoff,
    Landing,
};


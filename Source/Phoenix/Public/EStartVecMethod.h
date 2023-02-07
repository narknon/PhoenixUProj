#pragma once
#include "CoreMinimal.h"
#include "EStartVecMethod.generated.h"

UENUM(BlueprintType)
enum class EStartVecMethod : uint8 {
    None,
    ReferenceVector,
    RandomAngleOwnerForward,
    RandomAngleToTarget,
};


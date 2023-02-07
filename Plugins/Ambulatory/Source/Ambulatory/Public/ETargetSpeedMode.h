#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.generated.h"

UENUM(BlueprintType)
namespace ETargetSpeedMode {
    enum Type {
        None,
        IsIdling,
        IsSlowWalking,
        IsWalking,
        IsWalkingOnly,
        IsFastWalking,
        IsFastWalkingOnly,
        IsJogging,
        IsJoggingOnly,
        IsSprinting,
    };
}


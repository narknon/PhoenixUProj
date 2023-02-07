#pragma once
#include "CoreMinimal.h"
#include "ELockStates.generated.h"

UENUM(BlueprintType)
enum class ELockStates : uint8 {
    Unlocked,
    Locked,
    LastLockState,
};


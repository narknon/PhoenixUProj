#pragma once
#include "CoreMinimal.h"
#include "EMinimalLockState.generated.h"

UENUM(BlueprintType)
enum class EMinimalLockState : uint8 {
    Unlocked,
    Locked,
};


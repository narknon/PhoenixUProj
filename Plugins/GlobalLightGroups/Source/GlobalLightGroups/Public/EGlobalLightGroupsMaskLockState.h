#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightGroupsMaskLockState.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightGroupsMaskLockState : uint8 {
    Unlocked,
    LockedOn,
    LockedOff,
};


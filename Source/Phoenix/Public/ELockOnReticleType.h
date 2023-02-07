#pragma once
#include "CoreMinimal.h"
#include "ELockOnReticleType.generated.h"

UENUM(BlueprintType)
enum class ELockOnReticleType : uint8 {
    None,
    LockedOn,
    AimMode,
    Both,
    Retaliate,
};


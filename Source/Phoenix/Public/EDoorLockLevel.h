#pragma once
#include "CoreMinimal.h"
#include "EDoorLockLevel.generated.h"

UENUM(BlueprintType)
enum class EDoorLockLevel : uint8 {
    Unlocked,
    Level_1,
    Level_2,
    Level_3,
    NeedsKeyToUnlock,
    ChildLock,
};


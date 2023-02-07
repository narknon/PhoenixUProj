#pragma once
#include "CoreMinimal.h"
#include "ELockLevel.generated.h"

UENUM(BlueprintType)
enum class ELockLevel : uint8 {
    LockLevel1,
    LockLevel2,
    LockLevel3,
};


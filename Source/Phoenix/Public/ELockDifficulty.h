#pragma once
#include "CoreMinimal.h"
#include "ELockDifficulty.generated.h"

UENUM(BlueprintType)
enum class ELockDifficulty : uint8 {
    Level_1,
    Level_2,
    Level_3,
    NeedsKey,
};


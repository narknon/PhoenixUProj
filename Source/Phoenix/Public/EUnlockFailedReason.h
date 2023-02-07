#pragma once
#include "CoreMinimal.h"
#include "EUnlockFailedReason.generated.h"

UENUM(BlueprintType)
enum class EUnlockFailedReason : uint8 {
    KeyNotFound,
    AlohomoraLevelNotMet,
};


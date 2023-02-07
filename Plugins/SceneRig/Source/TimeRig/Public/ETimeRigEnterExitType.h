#pragma once
#include "CoreMinimal.h"
#include "ETimeRigEnterExitType.generated.h"

UENUM(BlueprintType)
enum class ETimeRigEnterExitType : uint8 {
    Entering,
    EnteringInside,
    Exiting,
    Instant,
    Skip,
    Unknown,
};


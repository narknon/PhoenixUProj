#pragma once
#include "CoreMinimal.h"
#include "ESynchronizeMethod.generated.h"

UENUM(BlueprintType)
enum class ESynchronizeMethod : uint8 {
    Synchronize_None,
    Synchronize_Location,
    Synchronize_Schedule,
    Synchronize_LocationAndSchedule,
    Synchronize_ReleaseCustomT3,
    Synchronize_MAX UMETA(Hidden),
};


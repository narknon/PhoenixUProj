#pragma once
#include "CoreMinimal.h"
#include "ESpawnAOE.generated.h"

UENUM(BlueprintType)
enum class ESpawnAOE : uint8 {
    SuccessfulHit,
    FailedHit,
    Blocked,
    Deflected,
    FizzledOut,
};


#pragma once
#include "CoreMinimal.h"
#include "ELocatorState.generated.h"

UENUM(BlueprintType)
enum ELocatorState {
    WaitingToSpawn,
    FailedToSpawn,
    ActiveEvent,
    StreamWithLevel,
    Completed,
};


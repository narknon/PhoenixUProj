#pragma once
#include "CoreMinimal.h"
#include "ETimeRigPlayerState.generated.h"

UENUM(BlueprintType)
enum class ETimeRigPlayerState : uint8 {
    Uninitialized,
    PreparingToInitialize,
    Initializing,
    Active,
    Finishing,
    Finished,
};


#pragma once
#include "CoreMinimal.h"
#include "ENPC_SidekickUpdateState.generated.h"

UENUM(BlueprintType)
enum class ENPC_SidekickUpdateState : uint8 {
    None,
    Hover,
    StopMove,
    StoppingMove,
    StartMove,
    UpdateMove,
    Moving,
    ENPC_MAX UMETA(Hidden),
};


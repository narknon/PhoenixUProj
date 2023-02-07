#pragma once
#include "CoreMinimal.h"
#include "ENPC_ShutdownState.generated.h"

UENUM(BlueprintType)
enum class ENPC_ShutdownState : uint8 {
    None,
    Execution,
    Rendering,
    Disabled,
    ENPC_MAX UMETA(Hidden),
};


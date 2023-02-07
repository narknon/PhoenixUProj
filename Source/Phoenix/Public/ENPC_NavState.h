#pragma once
#include "CoreMinimal.h"
#include "ENPC_NavState.generated.h"

UENUM(BlueprintType)
enum class ENPC_NavState : uint8 {
    Unknown,
    On,
    Off,
    ENPC_MAX UMETA(Hidden),
};


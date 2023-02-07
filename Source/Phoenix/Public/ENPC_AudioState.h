#pragma once
#include "CoreMinimal.h"
#include "ENPC_AudioState.generated.h"

UENUM(BlueprintType)
enum class ENPC_AudioState : uint8 {
    None,
    Unaware,
    Alerted,
    Attacking,
    ENPC_MAX UMETA(Hidden),
};


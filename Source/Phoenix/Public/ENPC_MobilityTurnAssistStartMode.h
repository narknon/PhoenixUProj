#pragma once
#include "CoreMinimal.h"
#include "ENPC_MobilityTurnAssistStartMode.generated.h"

UENUM(BlueprintType)
enum class ENPC_MobilityTurnAssistStartMode : uint8 {
    None,
    Immediate,
    FromAnim,
    Delayed,
    ENPC_MAX UMETA(Hidden),
};


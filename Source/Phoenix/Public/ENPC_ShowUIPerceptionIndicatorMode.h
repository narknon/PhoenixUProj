#pragma once
#include "CoreMinimal.h"
#include "ENPC_ShowUIPerceptionIndicatorMode.generated.h"

UENUM(BlueprintType)
enum class ENPC_ShowUIPerceptionIndicatorMode : uint8 {
    Progression,
    AggroOnly,
    ENPC_MAX UMETA(Hidden),
};


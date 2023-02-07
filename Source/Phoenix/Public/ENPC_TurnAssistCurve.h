#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssistCurve.generated.h"

UENUM(BlueprintType)
enum class ENPC_TurnAssistCurve : uint8 {
    Main,
    Time,
    Speed,
    ENPC_MAX UMETA(Hidden),
};


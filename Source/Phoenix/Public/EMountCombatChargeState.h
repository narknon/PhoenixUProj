#pragma once
#include "CoreMinimal.h"
#include "EMountCombatChargeState.generated.h"

UENUM(BlueprintType)
enum class EMountCombatChargeState : uint8 {
    Inactive,
    IntoTransition,
    ChargeLoop,
    OutOfTransition,
};


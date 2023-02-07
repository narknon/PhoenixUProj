#pragma once
#include "CoreMinimal.h"
#include "EWorldFXRulesMoonPhase.generated.h"

UENUM(BlueprintType)
enum class EWorldFXRulesMoonPhase : uint8 {
    NewMoon,
    WaxingCrescent,
    FirstQuarter,
    WaxingGibbous,
    FullMoon,
    WaningGibbous,
    LastQuarter,
    WaningCrescent,
};


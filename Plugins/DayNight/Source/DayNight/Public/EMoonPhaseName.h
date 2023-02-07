#pragma once
#include "CoreMinimal.h"
#include "EMoonPhaseName.generated.h"

UENUM(BlueprintType)
enum class EMoonPhaseName : uint8 {
    NewMoon,
    WaxingCrescent,
    FirstQuarter,
    WaxingGibbous,
    FullMoon,
    WaningGibbous,
    LastQuarter,
    WaningCrescent,
};


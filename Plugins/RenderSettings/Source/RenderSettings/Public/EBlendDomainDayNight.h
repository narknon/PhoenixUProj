#pragma once
#include "CoreMinimal.h"
#include "EBlendDomainDayNight.generated.h"

UENUM(BlueprintType)
enum class EBlendDomainDayNight : uint8 {
    DayAndNight,
    DayOnly,
    NightOnly,
};


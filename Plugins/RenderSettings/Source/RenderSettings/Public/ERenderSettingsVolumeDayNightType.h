#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsVolumeDayNightType.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsVolumeDayNightType : uint8 {
    DayAndNight,
    DayOnly,
    NightOnly,
};


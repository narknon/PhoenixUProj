#pragma once
#include "CoreMinimal.h"
#include "EScheduleEnableDisable.generated.h"

UENUM(BlueprintType)
enum class EScheduleEnableDisable : uint8 {
    Ignore,
    Enable,
    DisableAndAbandonStations,
    DisableButStayInStation,
};


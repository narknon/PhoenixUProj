#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightGroupsTimeSpanOnOffState.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightGroupsTimeSpanOnOffState : uint8 {
    TurnedOn,
    TurnedOff,
};


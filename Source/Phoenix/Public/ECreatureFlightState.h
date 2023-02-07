#pragma once
#include "CoreMinimal.h"
#include "ECreatureFlightState.generated.h"

UENUM(BlueprintType)
enum class ECreatureFlightState : uint8 {
    NotFlying,
    Flying,
};


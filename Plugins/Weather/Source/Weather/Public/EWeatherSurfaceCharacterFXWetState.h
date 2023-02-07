#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfaceCharacterFXWetState.generated.h"

UENUM(BlueprintType)
enum class EWeatherSurfaceCharacterFXWetState : uint8 {
    Dry,
    FirstWet,
    Wet,
    FirstDry,
};


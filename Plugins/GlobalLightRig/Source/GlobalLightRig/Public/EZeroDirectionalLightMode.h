#pragma once
#include "CoreMinimal.h"
#include "EZeroDirectionalLightMode.generated.h"

UENUM(BlueprintType)
enum class EZeroDirectionalLightMode : uint8 {
    AllowZeroIntensity,
    TurnOffLight,
    ClampToMinimum,
};


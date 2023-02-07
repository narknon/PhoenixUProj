#pragma once
#include "CoreMinimal.h"
#include "EDayNightLightControllerOp.generated.h"

UENUM(BlueprintType)
enum class EDayNightLightControllerOp : uint8 {
    Disable,
    SetLightValue,
    ModulateLightValue,
};


#pragma once
#include "CoreMinimal.h"
#include "ELightParameterTimeBlendInput.generated.h"

UENUM(BlueprintType)
enum class ELightParameterTimeBlendInput : uint8 {
    TimeOfDay,
    NormalizedTime,
};


#pragma once
#include "CoreMinimal.h"
#include "EAnimatedLightComponentNoiseType.generated.h"

UENUM(BlueprintType)
enum class EAnimatedLightComponentNoiseType : uint8 {
    AddAndSubtract,
    AddOnly,
    SubtractOnly,
};


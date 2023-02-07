#pragma once
#include "CoreMinimal.h"
#include "EAnimatedLightExtraParameterValue.generated.h"

UENUM(BlueprintType)
enum class EAnimatedLightExtraParameterValue : uint8 {
    LightColor,
    LightIntensity,
    LightColorTimesIntensity,
    LightColorAndIntensity,
    OriginalColor,
    OriginalIntensity,
    OriginalColorTimesIntensity,
    OriginalColorAndIntensity,
    DeltaColor,
    DeltaIntensity,
    DeltaColorAndIntensity,
    RelativeIntensity,
};


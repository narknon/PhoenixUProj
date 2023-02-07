#pragma once
#include "CoreMinimal.h"
#include "EWorldBaseHeightAffect.generated.h"

UENUM(BlueprintType)
enum class EWorldBaseHeightAffect : uint8 {
    Clouds,
    ExponentialHeightFog,
    Atmosphere,
};


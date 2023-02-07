#pragma once
#include "CoreMinimal.h"
#include "ELightCullingDistanceOverride.generated.h"

UENUM(BlueprintType)
enum class ELightCullingDistanceOverride : uint8 {
    DoNotTouch,
    AlwaysOverride,
    UseMinimum,
    OnlyIfNotSet,
};


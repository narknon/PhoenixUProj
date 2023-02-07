#pragma once
#include "CoreMinimal.h"
#include "EProbeNightLightMoonDirection.generated.h"

UENUM(BlueprintType)
enum class EProbeNightLightMoonDirection : uint8 {
    FromSkyState,
    OppositeSun,
    FixedDirection,
};


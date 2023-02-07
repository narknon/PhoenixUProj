#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightGroupsSunAngle.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightGroupsSunAngle : uint8 {
    FullBrightSky,
    LowerLimbOnHorizon,
    CenterOnHorizon,
    UpperLimbOnHorizon,
    CivilTwilight,
    NauticalTwilight,
    AstronomicalTwilight,
};


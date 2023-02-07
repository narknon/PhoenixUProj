#pragma once
#include "CoreMinimal.h"
#include "EDayNightReportFog.generated.h"

UENUM(BlueprintType)
enum class EDayNightReportFog : uint8 {
    FogDensity,
    FogOpacity,
    FogDistances,
    FogInscattering,
    FogVolumetric,
};


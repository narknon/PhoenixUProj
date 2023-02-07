#pragma once
#include "CoreMinimal.h"
#include "ENiagaraHelpersMultiSpawnRateType.generated.h"

UENUM(BlueprintType)
enum class ENiagaraHelpersMultiSpawnRateType : uint8 {
    DoNotCompute,
    BoxVolume,
    SphereVolume,
    BoxSurfaceArea,
    SphereSurfaceArea,
    CircleSurfaceArea,
    ForceToOne,
};


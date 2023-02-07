#pragma once
#include "CoreMinimal.h"
#include "ENiagaraSpawnBoundsMethod.generated.h"

UENUM(BlueprintType)
enum class ENiagaraSpawnBoundsMethod : uint8 {
    Disabled,
    Radius,
    MajorAxisLength,
    ProjectedBoxSurfaceArea,
    ProjectedCircleSurfaceArea,
    BoxVolume,
    SphereVolume,
    BoxSurfaceArea,
    SphereSurfaceArea,
};


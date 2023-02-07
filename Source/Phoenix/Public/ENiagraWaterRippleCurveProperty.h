#pragma once
#include "CoreMinimal.h"
#include "ENiagraWaterRippleCurveProperty.generated.h"

UENUM(BlueprintType)
enum class ENiagraWaterRippleCurveProperty : uint8 {
    TargetMass,
    TargetVelocity,
    TargetVelocityZ,
    InstigatorMass,
    InstigatorVelocity,
    InstigatorVelocityZ,
    ImpactMass,
    ImpactVelocity,
    ImpactMomentum,
};


#pragma once
#include "CoreMinimal.h"
#include "EMultiFXOrientation.generated.h"

UENUM(BlueprintType)
enum class EMultiFXOrientation : uint8 {
    AnchorOrient,
    ZeroOrient,
    WandtipOrient,
    GroundOrient,
    InvertOrient,
    InstigatorOrient,
    ImpactPointOrient,
    TargetPointOrient,
    TowardInstigator,
    InstigatorToTarget,
    ZeroPitch,
    ZeroRoll,
    ZeroYaw,
    VelocityOrient,
    WeaponOrient,
};


#pragma once
#include "CoreMinimal.h"
#include "EWindVortexEnvelopeAffects.generated.h"

UENUM(BlueprintType)
enum class EWindVortexEnvelopeAffects : uint8 {
    Speed,
    Height,
    Radius,
    Strength,
};


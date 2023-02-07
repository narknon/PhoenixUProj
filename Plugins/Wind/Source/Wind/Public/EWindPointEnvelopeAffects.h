#pragma once
#include "CoreMinimal.h"
#include "EWindPointEnvelopeAffects.generated.h"

UENUM(BlueprintType)
enum class EWindPointEnvelopeAffects : uint8 {
    Speed,
    Radius,
    Strength,
};


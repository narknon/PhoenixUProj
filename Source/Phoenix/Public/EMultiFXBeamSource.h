#pragma once
#include "CoreMinimal.h"
#include "EMultiFXBeamSource.generated.h"

UENUM(BlueprintType)
enum class EMultiFXBeamSource : uint8 {
    Target,
    Instigator,
    BeamSourceProperty,
};


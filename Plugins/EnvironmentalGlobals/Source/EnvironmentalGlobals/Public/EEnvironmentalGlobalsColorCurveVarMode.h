#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsColorCurveVarMode.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsColorCurveVarMode : uint8 {
    Normal,
    Clamped,
    Unadjusted,
};


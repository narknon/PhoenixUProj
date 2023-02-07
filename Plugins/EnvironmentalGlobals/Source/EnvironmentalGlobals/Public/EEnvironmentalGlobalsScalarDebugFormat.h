#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsScalarDebugFormat.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsScalarDebugFormat : uint8 {
    None,
    EV100,
    PowerOf2,
    Invert,
};


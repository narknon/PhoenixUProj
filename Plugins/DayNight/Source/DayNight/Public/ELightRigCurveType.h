#pragma once
#include "CoreMinimal.h"
#include "ELightRigCurveType.generated.h"

UENUM(BlueprintType)
enum class ELightRigCurveType : uint8 {
    Absolute,
    Multiply,
    Add,
    Minimum,
    Maximum,
};


#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModTransform.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigModTransform : uint8 {
    None,
    Negate,
    Abs,
    OneMinus,
    Saturate,
    Square,
    Normalize,
};


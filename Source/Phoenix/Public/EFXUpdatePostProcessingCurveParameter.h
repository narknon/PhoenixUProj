#pragma once
#include "CoreMinimal.h"
#include "EFXUpdatePostProcessingCurveParameter.generated.h"

UENUM(BlueprintType)
enum class EFXUpdatePostProcessingCurveParameter : uint8 {
    None,
    BlendWeight,
    AllBlendablesWeight,
    Blendable0Weight,
    Blendable1Weight,
    Blendable2Weight,
    Blendable3Weight,
};


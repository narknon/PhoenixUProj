#pragma once
#include "CoreMinimal.h"
#include "EFXUpdatePostProcessingParameter.generated.h"

UENUM(BlueprintType)
enum class EFXUpdatePostProcessingParameter : uint8 {
    None,
    BlendWeight,
    AllBlendablesWeight,
    Blendable0Weight,
    Blendable1Weight,
    Blendable2Weight,
    Blendable3Weight,
    BlendInTime,
    BlendOutTime,
    DefaultBlendOutTime,
};


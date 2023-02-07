#pragma once
#include "CoreMinimal.h"
#include "EPostProcessingVarVector2D.generated.h"

UENUM(BlueprintType)
enum class EPostProcessingVarVector2D : uint8 {
    None,
    BloomConvolutionCenterUV,
};


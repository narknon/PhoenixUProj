#pragma once
#include "CoreMinimal.h"
#include "EPostProcessingVarTexture.generated.h"

UENUM(BlueprintType)
enum class EPostProcessingVarTexture : uint8 {
    None,
    BloomDirtMask,
    AutoExposureMeterMask,
    LensFlareBokehShape,
    ColorGradingLUT,
    BloomConvolutionTexture,
    AmbientCubemap,
};


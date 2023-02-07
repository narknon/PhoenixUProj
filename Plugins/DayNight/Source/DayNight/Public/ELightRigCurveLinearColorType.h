#pragma once
#include "CoreMinimal.h"
#include "ELightRigCurveLinearColorType.generated.h"

UENUM(BlueprintType)
enum class ELightRigCurveLinearColorType : uint8 {
    RGBA,
    RGBOneA,
    RGBZeroA,
    RGBTimesAOneA,
    RGBTimesAZeroA,
    RGBNormalizedOneA,
    RGBNormalizedZeroA,
    RGBNormalizedA,
    RGBNormalizedIntA,
    RGBGrayOneA,
    RGBGrayZeroA,
    RGBGrayA,
};


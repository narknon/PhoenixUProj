#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModLinearColorType.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigModLinearColorType : uint8 {
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


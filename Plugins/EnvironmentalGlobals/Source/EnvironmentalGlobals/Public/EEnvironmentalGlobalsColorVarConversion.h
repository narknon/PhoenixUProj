#pragma once
#include "CoreMinimal.h"
#include "EEnvironmentalGlobalsColorVarConversion.generated.h"

UENUM(BlueprintType)
enum class EEnvironmentalGlobalsColorVarConversion : uint8 {
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


#pragma once
#include "CoreMinimal.h"
#include "ESampleTextureToCurveAlphaChannel.generated.h"

UENUM(BlueprintType)
enum class ESampleTextureToCurveAlphaChannel : uint8 {
    TextureAlpha,
    FixedAlpha,
    AlphaIsOne,
    AlphaIsZero,
    AlphaIsIntensity,
};


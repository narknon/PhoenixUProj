#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEnvelopeColorMod.generated.h"

UENUM(BlueprintType)
enum class ESkinFXEnvelopeColorMod : uint8 {
    RGBONLY,
    ALPHAONLY,
    ALL,
};


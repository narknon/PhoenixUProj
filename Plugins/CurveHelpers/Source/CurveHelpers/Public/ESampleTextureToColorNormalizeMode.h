#pragma once
#include "CoreMinimal.h"
#include "ESampleTextureToColorNormalizeMode.generated.h"

UENUM(BlueprintType)
enum class ESampleTextureToColorNormalizeMode : uint8 {
    Intensity,
    Luminance,
    LuminanceBT709,
    LuminanceRMY,
    LuminanceYIQ,
    LuminanceATM,
    Magnitude,
    MagnitudeRG,
    MagnitudeGB,
    MagnitudeRB,
    RedComponent,
    GreenComponent,
    BlueComponent,
    MaxComponent,
};


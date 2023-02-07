#pragma once
#include "CoreMinimal.h"
#include "EEngineHDROutputDevice.generated.h"

UENUM(BlueprintType)
enum class EEngineHDROutputDevice : uint8 {
    sRGB,
    Rec709,
    ExplicitGammaMapping,
    ACES1000nit_ST2084_DolbyPQ,
    ACES2000nit_ST2084_DolbyPQ,
    ACES1000nit_ScRGB,
    ACES2000nit_ScRGB,
    LinearEXR,
    LinearFinalColor,
    LinearFinalColorToneCurve,
    ACES_SSST_ST2084_DolbyPQ,
    ACES_SSTS_ScRGB,
};


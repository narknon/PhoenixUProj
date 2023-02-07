#pragma once
#include "CoreMinimal.h"
#include "EFloatMultiChannelNoiseWaveform.generated.h"

UENUM(BlueprintType)
enum class EFloatMultiChannelNoiseWaveform : uint8 {
    CosineWave,
    SineWave,
    PerlinNoise,
};


#pragma once
#include "CoreMinimal.h"
#include "AkCodecId.generated.h"

UENUM(BlueprintType)
enum class AkCodecId : uint8 {
    None,
    PCM,
    ADPCM,
    XMA,
    Vorbis,
    AAC = 0xA,
    ATRAC9 = 0xC,
    OpusNX = 0x11,
    AkOpus = 0x13,
    AkOpusWEM,
};


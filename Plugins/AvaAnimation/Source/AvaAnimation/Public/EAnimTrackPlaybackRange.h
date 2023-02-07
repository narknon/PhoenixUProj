#pragma once
#include "CoreMinimal.h"
#include "EAnimTrackPlaybackRange.generated.h"

UENUM(BlueprintType)
enum class EAnimTrackPlaybackRange : uint8 {
    FullClipRange,
    StartEndOffsets,
    StartEndFractions,
    StartOffsetWithDuration,
};


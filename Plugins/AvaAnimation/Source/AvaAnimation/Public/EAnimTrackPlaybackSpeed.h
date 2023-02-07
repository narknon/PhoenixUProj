#pragma once
#include "CoreMinimal.h"
#include "EAnimTrackPlaybackSpeed.generated.h"

UENUM(BlueprintType)
enum class EAnimTrackPlaybackSpeed : uint8 {
    NaturalSpeed,
    UseForcedDuration,
    UseForcedPlayRate,
};


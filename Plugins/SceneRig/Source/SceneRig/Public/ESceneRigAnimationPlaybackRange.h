#pragma once
#include "CoreMinimal.h"
#include "ESceneRigAnimationPlaybackRange.generated.h"

UENUM(BlueprintType)
enum class ESceneRigAnimationPlaybackRange : uint8 {
    FullClipRange,
    StartEndOffsets,
    StartEndFractions,
    StartOffsetWithDuration,
};


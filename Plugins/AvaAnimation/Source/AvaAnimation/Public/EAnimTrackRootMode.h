#pragma once
#include "CoreMinimal.h"
#include "EAnimTrackRootMode.generated.h"

UENUM(BlueprintType)
enum class EAnimTrackRootMode : uint8 {
    CompletelyIgnoreRoot,
    EnableRootMotion,
    KeepRootAnimationWithoutRootMotion,
    UseContentSetting,
};


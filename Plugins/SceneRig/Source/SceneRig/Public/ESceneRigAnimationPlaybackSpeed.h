#pragma once
#include "CoreMinimal.h"
#include "ESceneRigAnimationPlaybackSpeed.generated.h"

UENUM(BlueprintType)
enum class ESceneRigAnimationPlaybackSpeed : uint8 {
    NaturalSpeed,
    FillActionDuration,
    UseSpeedMultiplier,
};


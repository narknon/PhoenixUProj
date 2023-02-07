#pragma once
#include "CoreMinimal.h"
#include "EMapIconAnimationLoopType.generated.h"

UENUM(BlueprintType)
enum EMapIconAnimationLoopType {
    MAP_ICON_ANIMATION_LOOP_TYPE_ONE_SHOT,
    MAP_ICON_ANIMATION_LOOP_TYPE_LOOPING,
    MAP_ICON_ANIMATION_LOOP_TYPE_BOUNCE,
    MAP_ICON_ANIMATION_LOOP_TYPE_MAX UMETA(Hidden),
};


#pragma once
#include "CoreMinimal.h"
#include "EMapIconAnimationStopType.generated.h"

UENUM(BlueprintType)
enum EMapIconAnimationStopType {
    MAP_ICON_ANIMATION_STOP_TYPE_ALL,
    MAP_ICON_ANIMATION_STOP_TYPE_POSITION_ONLY,
    MAP_ICON_ANIMATION_STOP_TYPE_SCALE_ONLY,
    MAP_ICON_ANIMATION_STOP_TYPE_MAX UMETA(Hidden),
};


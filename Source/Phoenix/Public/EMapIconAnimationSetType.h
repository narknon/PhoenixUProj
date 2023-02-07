#pragma once
#include "CoreMinimal.h"
#include "EMapIconAnimationSetType.generated.h"

UENUM(BlueprintType)
enum EMapIconAnimationSetType {
    MAP_ICON_ANIMATION_SET_TYPE_APPEND,
    MAP_ICON_ANIMATION_SET_TYPE_DIRECT,
    MAP_ICON_ANIMATION_SET_TYPE_LERP,
    MAP_ICON_ANIMATION_SET_TYPE_MAX UMETA(Hidden),
};


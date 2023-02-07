#pragma once
#include "CoreMinimal.h"
#include "EMapIconAnimationBinding.generated.h"

UENUM(BlueprintType)
enum EMapIconAnimationBinding {
    MAP_ICON_ANIMATION_BINDING_TRANSLATION,
    MAP_ICON_ANIMATION_BINDING_SCALE,
    MAP_ICON_ANIMATION_BINDING_MAX UMETA(Hidden),
};


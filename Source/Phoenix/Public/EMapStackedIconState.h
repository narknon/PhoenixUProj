#pragma once
#include "CoreMinimal.h"
#include "EMapStackedIconState.generated.h"

UENUM(BlueprintType)
enum EMapStackedIconState {
    MAP_STACKED_ICON_STATE_NONE,
    MAP_STACKED_ICON_STATE_IS_HOVERED,
    MAP_STACKED_ICON_STATE_TRIGGER_CHOOSER,
    MAP_STACKED_ICON_STATE_ANIMATE_CHOOSER,
    MAP_STACKED_ICON_STATE_ANIMATE_CHOOSER_REVERSE,
    MAP_STACKED_ICON_STATE_IN_CHOOSER,
    MAP_STACKED_ICON_STATE_MAX UMETA(Hidden),
};


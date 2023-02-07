#pragma once
#include "CoreMinimal.h"
#include "EMapPostFadeState.generated.h"

UENUM(BlueprintType)
enum EMapPostFadeState {
    MAP_POST_FADE_STATE_NONE,
    MAP_POST_FADE_STATE_NEW_MAP,
    MAP_POST_FADE_STATE_CLOSE,
    MAP_POST_FADE_STATE_MAX UMETA(Hidden),
};


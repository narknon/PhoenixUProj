#pragma once
#include "CoreMinimal.h"
#include "EStoryEavesdropState.generated.h"

UENUM(BlueprintType)
enum EStoryEavesdropState {
    EAV_STATE_NONE,
    EAV_STATE_NOT_STARTED,
    EAV_STATE_PLAYING,
    EAV_STATE_FINISHED,
    EAV_STATE_COUNT,
    EAV_STATE_MAX UMETA(Hidden),
};


#pragma once
#include "CoreMinimal.h"
#include "EAsyncLoadAnimationState.generated.h"

UENUM(BlueprintType)
enum class EAsyncLoadAnimationState : uint8 {
    NOT_REQUESTED,
    REQUEST_IN_PROGRESS,
    REQUEST_COMPLETED,
};


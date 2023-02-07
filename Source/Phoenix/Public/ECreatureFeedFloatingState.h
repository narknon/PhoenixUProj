#pragma once
#include "CoreMinimal.h"
#include "ECreatureFeedFloatingState.generated.h"

UENUM(BlueprintType)
enum class ECreatureFeedFloatingState : uint8 {
    Static,
    FreeFloating,
    FloatingToTargetTransform,
    AttachedToTransform,
};


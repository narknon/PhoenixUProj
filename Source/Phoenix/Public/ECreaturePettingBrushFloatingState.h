#pragma once
#include "CoreMinimal.h"
#include "ECreaturePettingBrushFloatingState.generated.h"

UENUM(BlueprintType)
enum class ECreaturePettingBrushFloatingState : uint8 {
    FreeFloating,
    FloatingToTargetTransform,
    AttachedToTransform,
};


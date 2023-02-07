#pragma once
#include "CoreMinimal.h"
#include "EUMGInputAxis.generated.h"

UENUM(BlueprintType)
enum class EUMGInputAxis : uint8 {
    UMGMapZoomIn,
    UMGMapZoomOut,
    UMGMapScreenMove_X,
    UMGMapScreenMove_Y,
    UMGLeftThumbStickXAxis,
    UMGLeftThumbStickYAxis,
    UMGRightThumbStickXAxis,
    UMGRightThumbStickYAxis,
    UMGLeftTriggerAxis,
    UMGRightTriggerAxis,
    UMGTouchpadX,
    UMGTouchpadY,
    UMGMouseWheelAxis,
    UMGMouseX,
    UMGMouseY,
    UMGInputAxis_MAX UMETA(Hidden),
};


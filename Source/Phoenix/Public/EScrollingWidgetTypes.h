#pragma once
#include "CoreMinimal.h"
#include "EScrollingWidgetTypes.generated.h"

UENUM(BlueprintType)
enum class EScrollingWidgetTypes : uint8 {
    SCROLLING_WIDGET_TYPE_NONE,
    SCROLLING_WIDGET_TYPE_LEFT_TO_RIGHT,
    SCROLLING_WIDGET_TYPE_RIGHT_TO_LEFT,
    SCROLLING_WIDGET_TYPE_MAX UMETA(Hidden),
};


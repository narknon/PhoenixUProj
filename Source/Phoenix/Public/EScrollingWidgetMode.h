#pragma once
#include "CoreMinimal.h"
#include "EScrollingWidgetMode.generated.h"

UENUM(BlueprintType)
enum class EScrollingWidgetMode : uint8 {
    SCROLLING_WIDGET_MODE_NONE,
    SCROLLING_WIDGET_MODE_ALWAYS_ON,
    SCROLLING_WIDGET_MODE_ON_HOVER,
    SCROLLING_WIDGET_MODE_IF_TRUNCATED,
    SCROLLING_WIDGET_MODE_MAX UMETA(Hidden),
};


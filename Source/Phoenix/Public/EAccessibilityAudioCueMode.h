#pragma once
#include "CoreMinimal.h"
#include "EAccessibilityAudioCueMode.generated.h"

UENUM(BlueprintType)
enum EAccessibilityAudioCueMode {
    ACCESSIBILITY_EVENT_MODE_ONE_SHOT,
    ACCESSIBILITY_EVENT_MODE_ENTER,
    ACCESSIBILITY_EVENT_MODE_LEAVE,
    ACCESSIBILITY_EVENT_MODE_MAX UMETA(Hidden),
};


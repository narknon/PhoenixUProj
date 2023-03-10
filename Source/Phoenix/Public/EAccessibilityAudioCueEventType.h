#pragma once
#include "CoreMinimal.h"
#include "EAccessibilityAudioCueEventType.generated.h"

UENUM(BlueprintType)
enum EAccessibilityAudioCueEventType {
    ACCESSIBILITY_EVENT_TYPE_INTERACT,
    ACCESSIBILITY_EVENT_TYPE_FOOTSTEPS,
    ACCESSIBILITY_EVENT_TYPE_SPELLCASTER,
    ACCESSIBILITY_EVENT_TYPE_ALERT,
    ACCESSIBILITY_EVENT_TYPE_BEAST_ROAR,
    ACCESSIBILITY_EVENT_TYPE_DESTRUCTIBLE,
    ACCESSIBILITY_EVENT_TYPE_RUNNING_WATER,
    ACCESSIBILITY_EVENT_TYPE_DOOR_OPENCLOSE,
    ACCESSIBILITY_EVENT_TYPE_SHOW_NEGATIVE_INTERACTIONS,
    ACCESSIBILITY_EVENT_TYPE_BROOM,
    ACCESSIBILITY_EVENT_TYPE_LOOT,
    ACCESSIBILITY_EVENT_TYPE_BEAST_AWARE,
    ACCESSIBILITY_EVENT_TYPE_HIT,
    ACCESSIBILITY_EVENT_TYPE_AMBIENT_CONVERSATION,
    ACCESSIBILITY_EVENT_TYPE_STEALTH_DETECTED,
    ACCESSIBILITY_EVENT_TYPE_REVELIO_BELL,
    ACCESSIBILITY_EVENT_TYPE_NONE,
    ACCESSIBILITY_EVENT_TYPE_MAX UMETA(Hidden),
};


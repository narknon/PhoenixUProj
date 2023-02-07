#pragma once
#include "CoreMinimal.h"
#include "ESkinFXAutoTriggerDelegateEvent.generated.h"

UENUM(BlueprintType)
enum class ESkinFXAutoTriggerDelegateEvent : uint8 {
    Event_Start,
    Event_Stop,
    Event_MAX UMETA(Hidden),
};


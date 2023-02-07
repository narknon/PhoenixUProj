#pragma once
#include "CoreMinimal.h"
#include "EWindSourceEnvelopeTriggerEvent.generated.h"

UENUM(BlueprintType)
enum class EWindSourceEnvelopeTriggerEvent : uint8 {
    Trigger,
    Done,
};


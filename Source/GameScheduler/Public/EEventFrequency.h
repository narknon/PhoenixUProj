#pragma once
#include "CoreMinimal.h"
#include "EEventFrequency.generated.h"

UENUM(BlueprintType)
enum EEventFrequency {
    EVENT_FREQ_CONTINUOUS,
    EVENT_FREQ_ONCE,
    EVENT_FREQ_MAX UMETA(Hidden),
};


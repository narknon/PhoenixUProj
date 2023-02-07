#pragma once
#include "CoreMinimal.h"
#include "EEventType.generated.h"

UENUM(BlueprintType)
enum EEventType {
    EVENT_TYPE_HOURLY,
    EVENT_TYPE_MINUTELY,
    EVENT_TYPE_TIME,
    EVENT_TYPE_DELTA_TIME,
    EVENT_TYPE_MAX UMETA(Hidden),
};


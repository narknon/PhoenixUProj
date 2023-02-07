#pragma once
#include "CoreMinimal.h"
#include "ESchedulerTimeDateType.generated.h"

UENUM(BlueprintType)
enum ESchedulerTimeDateType {
    SCHEDULER_TYPE_TIME,
    SCHEDULER_TYPE_DATE,
    SCHEDULER_TYPE_DAY,
    SCHEDULER_TYPE_MONTH,
    SCHEDULER_TYPE_TIME_AND_DATE,
    SCHEDULER_TYPE_MAX UMETA(Hidden),
};


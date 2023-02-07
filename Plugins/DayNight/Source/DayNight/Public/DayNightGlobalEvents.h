#pragma once
#include "CoreMinimal.h"
#include "DayNightEventTrackers.h"
#include "DayNightGlobalEvents.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FDayNightGlobalEvents : public FDayNightEventTrackers {
    GENERATED_BODY()
public:
    FDayNightGlobalEvents();
};


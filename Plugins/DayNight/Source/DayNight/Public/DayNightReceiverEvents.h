#pragma once
#include "CoreMinimal.h"
#include "DayNightEventTrackers.h"
#include "DayNightReceiverEvents.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FDayNightReceiverEvents : public FDayNightEventTrackers {
    GENERATED_BODY()
public:
    FDayNightReceiverEvents();
};


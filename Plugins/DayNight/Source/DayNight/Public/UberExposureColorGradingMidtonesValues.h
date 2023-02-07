#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGradingValues.h"
#include "UberExposureColorGradingMidtonesValues.generated.h"

USTRUCT(BlueprintType)
struct FUberExposureColorGradingMidtonesValues : public FUberExposureColorGradingValues {
    GENERATED_BODY()
public:
    DAYNIGHT_API FUberExposureColorGradingMidtonesValues();
};


#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGradingValues.h"
#include "UberExposureColorGradingGlobalValues.generated.h"

USTRUCT(BlueprintType)
struct FUberExposureColorGradingGlobalValues : public FUberExposureColorGradingValues {
    GENERATED_BODY()
public:
    DAYNIGHT_API FUberExposureColorGradingGlobalValues();
};


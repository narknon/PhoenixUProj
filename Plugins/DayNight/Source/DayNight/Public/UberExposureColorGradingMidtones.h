#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGrading.h"
#include "UberExposureColorGradingMidtones.generated.h"

USTRUCT(BlueprintType)
struct FUberExposureColorGradingMidtones : public FUberExposureColorGrading {
    GENERATED_BODY()
public:
    DAYNIGHT_API FUberExposureColorGradingMidtones();
};


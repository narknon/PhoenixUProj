#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGrading.h"
#include "UberExposureColorGradingGlobal.generated.h"

USTRUCT(BlueprintType)
struct FUberExposureColorGradingGlobal : public FUberExposureColorGrading {
    GENERATED_BODY()
public:
    DAYNIGHT_API FUberExposureColorGradingGlobal();
};


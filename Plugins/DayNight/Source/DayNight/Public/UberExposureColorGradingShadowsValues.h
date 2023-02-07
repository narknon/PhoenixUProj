#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGradingValues.h"
#include "UberExposureColorGradingShadowsValues.generated.h"

USTRUCT(BlueprintType)
struct FUberExposureColorGradingShadowsValues : public FUberExposureColorGradingValues {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ShadowsMaxValue;
    
    DAYNIGHT_API FUberExposureColorGradingShadowsValues();
};


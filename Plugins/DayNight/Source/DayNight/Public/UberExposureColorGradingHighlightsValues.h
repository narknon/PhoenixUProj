#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGradingValues.h"
#include "UberExposureColorGradingHighlightsValues.generated.h"

USTRUCT(BlueprintType)
struct FUberExposureColorGradingHighlightsValues : public FUberExposureColorGradingValues {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HighlightsMinValue;
    
    DAYNIGHT_API FUberExposureColorGradingHighlightsValues();
};


#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGrading.h"
#include "UberExposureColorGradingHighlights.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FUberExposureColorGradingHighlights : public FUberExposureColorGrading {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseHighlightsMin: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* HighlightsMin;
    
    DAYNIGHT_API FUberExposureColorGradingHighlights();
};


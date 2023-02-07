#pragma once
#include "CoreMinimal.h"
#include "LastRenderedExposure.h"
#include "LastRenderedExposureRunningAverage.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FLastRenderedExposureRunningAverage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLastRenderedExposure Average;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Samples;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalSamples;
    
    FLastRenderedExposureRunningAverage();
};


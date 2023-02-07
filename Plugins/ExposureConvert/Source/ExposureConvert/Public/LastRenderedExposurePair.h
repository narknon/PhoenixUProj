#pragma once
#include "CoreMinimal.h"
#include "LastRenderedExposure.h"
#include "LastRenderedExposureRunningAverage.h"
#include "LastRenderedExposurePair.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FLastRenderedExposurePair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLastRenderedExposure Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLastRenderedExposure Filtered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLastRenderedExposureRunningAverage History;
    
    FLastRenderedExposurePair();
};


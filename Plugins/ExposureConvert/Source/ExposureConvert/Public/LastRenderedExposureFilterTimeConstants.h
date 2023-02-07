#pragma once
#include "CoreMinimal.h"
#include "LastRenderedExposureFilterTimeConstants.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FLastRenderedExposureFilterTimeConstants {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AverageLuminance;
    
    FLastRenderedExposureFilterTimeConstants();
};


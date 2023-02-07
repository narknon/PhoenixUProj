#pragma once
#include "CoreMinimal.h"
#include "LastRenderedExposure.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FLastRenderedExposure {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoExposureEV100;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AverageViewLuminanceEV100;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AverageLuminanceEV100;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 FrameNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    FLastRenderedExposure();
};


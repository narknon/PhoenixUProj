#pragma once
#include "CoreMinimal.h"
#include "LastRenderedExposureUnreal.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FLastRenderedExposureUnreal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AverageViewLuminance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AverageLuminance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AverageBrightness;
    
    FLastRenderedExposureUnreal();
};


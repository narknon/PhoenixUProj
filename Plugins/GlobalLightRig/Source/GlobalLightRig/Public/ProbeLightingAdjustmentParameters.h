#pragma once
#include "CoreMinimal.h"
#include "ProbeLightingAdjustmentParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FProbeLightingAdjustmentParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeOutsideIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeInsideIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeOutsideSaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeInsideSaturation;
    
    FProbeLightingAdjustmentParameters();
};


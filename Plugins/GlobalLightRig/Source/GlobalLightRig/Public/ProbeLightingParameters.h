#pragma once
#include "CoreMinimal.h"
#include "ProbeContactShadowsParameters.h"
#include "ProbeLightingAdjustmentParameters.h"
#include "ProbeLightingToneMapParameters.h"
#include "ProbeLightingParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FProbeLightingParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingAdjustmentParameters Adjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingToneMapParameters ToneMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeContactShadowsParameters ContactShadows;
    
    FProbeLightingParameters();
};


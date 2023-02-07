#pragma once
#include "CoreMinimal.h"
#include "ProbeContactShadowsParametersOverride.h"
#include "ProbeLightingAdjustmentParametersOverride.h"
#include "ProbeLightingToneMapParametersOverride.h"
#include "ProbeLightingParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FProbeLightingParametersOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingAdjustmentParametersOverride Adjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingToneMapParametersOverride ToneMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeContactShadowsParametersOverride ContactShadows;
    
    FProbeLightingParametersOverride();
};


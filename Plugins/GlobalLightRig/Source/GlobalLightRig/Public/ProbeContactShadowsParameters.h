#pragma once
#include "CoreMinimal.h"
#include "ProbeContactShadowsParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FProbeContactShadowsParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeContactShadowsMinValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeContactShadowsLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeContactShadowsConeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeContactShadowsFalloffExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ProbeContactShadowsDepthTolerance;
    
    FProbeContactShadowsParameters();
};


#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WLightProbesBlendData -FallbackName=WLightProbesBlendData
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WLightProbesCaptureEvaluator -FallbackName=WLightProbesCaptureEvaluator
#include "LightProbeCaptureSetupComputer.h"
#include "WLightProbesBlendData.h"
#include "WLightProbesCaptureEvaluator.h"
#include "LightProbeCaptureTimeSlot.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FLightProbeCaptureTimeSlot : public FWLightProbesCaptureEvaluator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightProbeCaptureSetupComputer Computer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWLightProbesBlendData ProbesBlendData;
    
public:
    FLightProbeCaptureTimeSlot();
};


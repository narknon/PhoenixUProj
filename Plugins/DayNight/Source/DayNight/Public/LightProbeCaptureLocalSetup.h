#pragma once
#include "CoreMinimal.h"
#include "WLightProbesVolumeCaptureSetup.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WLightProbesVolumeCaptureSetup -FallbackName=WLightProbesVolumeCaptureSetup
#include "LightProbeCaptureLocalSetup.generated.h"

class ULightProbeCaptureSetup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightProbeCaptureLocalSetup : public UWLightProbesVolumeCaptureSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightProbeCaptureSetup* CaptureSetup;
    
    ULightProbeCaptureLocalSetup();
};


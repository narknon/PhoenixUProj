#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WLightProbesVolumeCaptureSetup -FallbackName=WLightProbesVolumeCaptureSetup
#include "LightProbeCaptureSetupComputer.h"
#include "WLightProbesVolumeCaptureSetup.h"
#include "LightProbeCaptureLocalFixedSetup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightProbeCaptureLocalFixedSetup : public UWLightProbesVolumeCaptureSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightProbeCaptureSetupComputer Computer;
    
    ULightProbeCaptureLocalFixedSetup();
};


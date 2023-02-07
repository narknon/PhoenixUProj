#pragma once
#include "CoreMinimal.h"
#include "TimeSource.h"
#include "TimeSourceLightProbeCapture.generated.h"

class ULightProbeCaptureSetup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceLightProbeCapture : public UTimeSource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightProbeCaptureSetup* CaptureSetup;
    
    UTimeSourceLightProbeCapture();
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LightProbeCaptureSetupComputer.h"
#include "LightProbeCaptureSetup.generated.h"

UCLASS(Blueprintable)
class DAYNIGHT_API ULightProbeCaptureSetup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightProbeCaptureSetupComputer Computer;
    
    ULightProbeCaptureSetup();
};


#pragma once
#include "CoreMinimal.h"
#include "AnimatedVectorPropertyDriver.h"
#include "SRCameraTrackingFocusSettings.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSRCameraTrackingFocusSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedVectorPropertyDriver RelativeOffset;
    
    FSRCameraTrackingFocusSettings();
};


#pragma once
#include "CoreMinimal.h"
#include "AnimatedBoolPropertyDriver.h"
#include "AnimatedFloatPropertyDriver.h"
#include "AnimatedIntegerPropertyDriver.h"
#include "SRCameraTrackingFocusSettings.h"
#include "SRCameraFocusSettings.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSRCameraFocusSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedIntegerPropertyDriver FocusMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver ManualFocusDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedBoolPropertyDriver bDrawDebugFocusPlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedBoolPropertyDriver bSmoothFocusChanges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver FocusSmoothingInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedFloatPropertyDriver FocusOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSRCameraTrackingFocusSettings TrackingFocusSettings;
    
    FSRCameraFocusSettings();
};


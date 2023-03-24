#include "SanctuaryPortalCaptureExit.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneCaptureComponentCubeIncremental -FallbackName=SceneCaptureComponentCubeIncremental

ASanctuaryPortalCaptureExit::ASanctuaryPortalCaptureExit(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneCaptureComponent = CreateDefaultSubobject<USceneCaptureComponentCubeIncremental>(TEXT("SceneCapture"));
}


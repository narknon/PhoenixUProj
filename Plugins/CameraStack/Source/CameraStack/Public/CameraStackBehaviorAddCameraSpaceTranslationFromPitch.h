#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector -FallbackName=RuntimeCurveVector
#include "CameraStackBehaviorBlend.h"
#include "RuntimeCurveVector.h"
#include "CameraStackBehaviorAddCameraSpaceTranslationFromPitch.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorAddCameraSpaceTranslationFromPitch : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveVector PitchToTranslationCurve;
    
    UCameraStackBehaviorAddCameraSpaceTranslationFromPitch();
};


#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector -FallbackName=RuntimeCurveVector
#include "CameraStackBehaviorBlend.h"
#include "RuntimeCurveVector.h"
#include "CameraStackBehaviorAddCameraSpaceTranslationFromRelativeTargetHeading.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorAddCameraSpaceTranslationFromRelativeTargetHeading : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveVector YawToTranslationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    UCameraStackBehaviorAddCameraSpaceTranslationFromRelativeTargetHeading();
};


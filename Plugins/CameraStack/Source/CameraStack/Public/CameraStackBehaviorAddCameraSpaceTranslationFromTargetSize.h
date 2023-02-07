#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector -FallbackName=RuntimeCurveVector
#include "CameraStackBehaviorBlend.h"
#include "RuntimeCurveVector.h"
#include "CameraStackBehaviorAddCameraSpaceTranslationFromTargetSize.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAddCameraSpaceTranslationFromTargetSize : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveVector TranslationOffsetFromTargetSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateAtRuntime;
    
    UCameraStackBehaviorAddCameraSpaceTranslationFromTargetSize();
};


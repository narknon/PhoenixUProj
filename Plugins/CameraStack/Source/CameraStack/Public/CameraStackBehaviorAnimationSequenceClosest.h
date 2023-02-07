#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorAnimationBase.h"
#include "CameraStackBehaviorAnimationSequenceClosest.generated.h"

class UAnimSequenceBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAnimationSequenceClosest : public UCameraStackBehaviorAnimationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> AnimSequenceOptions;
    
    UCameraStackBehaviorAnimationSequenceClosest();
};


#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorAnimationBase.h"
#include "CameraStackBehaviorAnimationSequence.generated.h"

class UAnimSequenceBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAnimationSequence : public UCameraStackBehaviorAnimationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* SequenceToPlay;
    
    UCameraStackBehaviorAnimationSequence();
};


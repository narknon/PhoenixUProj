#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "AnimationClip_Direct.generated.h"

class UAnimSequenceBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationClip_Direct : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* AnimationClip;
    
    UAnimationClip_Direct();
};


#pragma once
#include "CoreMinimal.h"
#include "AnimationProvider.h"
#include "Animation_ScratchAnimation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimation_ScratchAnimation : public UAnimationProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedTake;
    
    UAnimation_ScratchAnimation();
};


#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "AnimationClip_AblAbility.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ABLECORE_API UAnimationClip_AblAbility : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UAnimationClip_AblAbility();
};


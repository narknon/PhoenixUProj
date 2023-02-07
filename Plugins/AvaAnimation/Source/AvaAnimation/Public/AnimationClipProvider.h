#pragma once
#include "CoreMinimal.h"
#include "AnimationProvider.h"
#include "AnimationClipProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationClipProvider : public UAnimationProvider {
    GENERATED_BODY()
public:
    UAnimationClipProvider();
};


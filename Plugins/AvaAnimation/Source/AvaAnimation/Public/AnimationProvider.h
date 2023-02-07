#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "AnimationProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationProvider : public UObjectProvider {
    GENERATED_BODY()
public:
    UAnimationProvider();
};


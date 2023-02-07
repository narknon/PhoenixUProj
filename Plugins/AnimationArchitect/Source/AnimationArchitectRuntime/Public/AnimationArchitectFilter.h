#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationArchitectFilter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ANIMATIONARCHITECTRUNTIME_API UAnimationArchitectFilter : public UObject {
    GENERATED_BODY()
public:
    UAnimationArchitectFilter();
};


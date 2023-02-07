#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationArchitectTagProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, DefaultToInstanced, EditInlineNew)
class ANIMATIONARCHITECTRUNTIME_API UAnimationArchitectTagProvider : public UObject {
    GENERATED_BODY()
public:
    UAnimationArchitectTagProvider();
};


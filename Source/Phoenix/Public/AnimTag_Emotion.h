#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_Emotion.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimTag_Emotion : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UAnimTag_Emotion();
};


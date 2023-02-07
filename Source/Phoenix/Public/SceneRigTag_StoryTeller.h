#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "SceneRigTag_StoryTeller.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigTag_StoryTeller : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    USceneRigTag_StoryTeller();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ObjectFade.h"
#include "SceneAction_ObjectFadeIn.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ObjectFadeIn : public USceneAction_ObjectFade {
    GENERATED_BODY()
public:
    USceneAction_ObjectFadeIn();
};


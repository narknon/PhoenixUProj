#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ObjectFade.h"
#include "SceneAction_ObjectFadeOut.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ObjectFadeOut : public USceneAction_ObjectFade {
    GENERATED_BODY()
public:
    USceneAction_ObjectFadeOut();
};


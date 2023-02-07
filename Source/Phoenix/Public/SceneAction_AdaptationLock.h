#pragma once
#include "CoreMinimal.h"
#include "SceneAction_Adaptation.h"
#include "SceneAction_AdaptationLock.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AdaptationLock : public USceneAction_Adaptation {
    GENERATED_BODY()
public:
    USceneAction_AdaptationLock();
};


#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_WaitForDeath.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneAction_WaitForDeath : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    USceneAction_WaitForDeath();
};


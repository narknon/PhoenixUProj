#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_SpawnActorAllowAsChild.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_SpawnActorAllowAsChild : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    USceneAction_SpawnActorAllowAsChild();
};


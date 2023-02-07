#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_ParticleSystemTrigger.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_ParticleSystemTrigger : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    USceneAction_ParticleSystemTrigger();
};


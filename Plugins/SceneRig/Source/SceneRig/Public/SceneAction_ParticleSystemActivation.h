#pragma once
#include "CoreMinimal.h"
#include "EParticleSystemActivation.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_ParticleSystemActivation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_ParticleSystemActivation : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EParticleSystemActivation Activation;
    
    USceneAction_ParticleSystemActivation();
};


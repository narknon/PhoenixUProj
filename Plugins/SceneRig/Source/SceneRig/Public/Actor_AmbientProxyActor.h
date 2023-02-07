#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "AmbientProxyActorReference.h"
#include "SceneRigParticipant.h"
#include "Actor_AmbientProxyActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_AmbientProxyActor : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmbientProxyActorReference AmbientProxy;
    
    UActor_AmbientProxyActor();
    
    // Fix for true pure virtual functions not being implemented
};


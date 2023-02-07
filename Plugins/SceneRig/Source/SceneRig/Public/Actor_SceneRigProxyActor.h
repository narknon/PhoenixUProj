#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_SceneRigProxyActor.generated.h"

class USceneRigProxyActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_SceneRigProxyActor : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigProxyActor* ProxyActor;
    
    UActor_SceneRigProxyActor();
};


#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_SceneRigParentProxyActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_SceneRigParentProxyActor : public UActorProvider {
    GENERATED_BODY()
public:
    UActor_SceneRigParentProxyActor();
};


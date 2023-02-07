#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_SceneRigActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_SceneRigActor : public UActorProvider {
    GENERATED_BODY()
public:
    UActor_SceneRigActor();
};


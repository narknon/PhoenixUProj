#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "Templates/SubclassOf.h"
#include "Actor_MountCreature.generated.h"

class ACreatureMountHandler;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_MountCreature : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACreatureMountHandler> MountHandlerClass;
    
    UActor_MountCreature();
    
    // Fix for true pure virtual functions not being implemented
};


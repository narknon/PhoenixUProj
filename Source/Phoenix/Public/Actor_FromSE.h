#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "Actor_FromSE.generated.h"

class UScheduledEntity;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_FromSE : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UScheduledEntity* ScheduledEntity;
    
    UActor_FromSE();
    
    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "WorldActorReference.h"
#include "Actor_FromDOV.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_FromDOV : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldActorReference DOVActorReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnGroupName;
    
    UActor_FromDOV();
    
    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "Actor_FromDOVWithName.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_FromDOVWithName : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DOVActorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnGroupName;
    
    UActor_FromDOVWithName();
    
    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "ActorByStat.h"
#include "StatList.h"
#include "Actor_ByStat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_ByStat : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatList Stat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActorByStat> Actors;
    
    UActor_ByStat();
    
    // Fix for true pure virtual functions not being implemented
};


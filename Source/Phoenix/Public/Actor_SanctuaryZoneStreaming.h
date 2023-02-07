#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "Actor_SanctuaryZoneStreaming.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_SanctuaryZoneStreaming : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ZoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForParallelStreamingComplete;
    
    UActor_SanctuaryZoneStreaming();
    
    // Fix for true pure virtual functions not being implemented
};


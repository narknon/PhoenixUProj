#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParticipant.h"
#include "WorldActorReference.h"
#include "Actor_FromStreamingPlaceholder.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_FromStreamingPlaceholder : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldActorReference StreamingPlaceholder;
    
    UActor_FromStreamingPlaceholder();
    
    // Fix for true pure virtual functions not being implemented
};


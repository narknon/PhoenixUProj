#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SpawnSelectInfo.h"
#include "SceneRigParticipant.h"
#include "Actor_ByCharacterID.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UActor_ByCharacterID : public UActorProvider, public ISceneRigParticipant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnSelectInfo DBInfo;
    
    UActor_ByCharacterID();
    
    // Fix for true pure virtual functions not being implemented
};


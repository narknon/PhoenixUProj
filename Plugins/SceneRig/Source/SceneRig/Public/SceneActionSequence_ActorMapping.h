#pragma once
#include "CoreMinimal.h"
#include "SceneActionSequence_SequenceActorName.h"
#include "SceneActionSequence_ActorMapping.generated.h"

class UActorProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneActionSequence_ActorMapping {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneActionSequence_SequenceActorName ActorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* AssignedActor;
    
    FSceneActionSequence_ActorMapping();
};


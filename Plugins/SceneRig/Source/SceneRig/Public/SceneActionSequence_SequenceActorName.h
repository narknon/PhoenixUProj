#pragma once
#include "CoreMinimal.h"
#include "SceneActionSequence_SequenceActorName.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneActionSequence_SequenceActorName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SequenceActorName;
    
    FSceneActionSequence_SequenceActorName();
};


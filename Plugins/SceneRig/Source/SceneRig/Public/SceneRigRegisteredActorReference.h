#pragma once
#include "CoreMinimal.h"
#include "SceneRigRegisteredActorReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigRegisteredActorReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RegisteredName;
    
    FSceneRigRegisteredActorReference();
};


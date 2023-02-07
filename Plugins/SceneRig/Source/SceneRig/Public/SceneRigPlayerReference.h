#pragma once
#include "CoreMinimal.h"
#include "SceneRigPlayerReference.generated.h"

class USceneRigPlayer;

USTRUCT(BlueprintType)
struct FSceneRigPlayerReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USceneRigPlayer* Player;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneRigPlayer> WeakPlayer;
    
    SCENERIG_API FSceneRigPlayerReference();
};


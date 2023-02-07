#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SceneRigPlayerReference.h"
#include "SceneRigPlayerManager.generated.h"

class USceneRigPlayer;

UCLASS(Blueprintable, NotPlaceable)
class SCENERIG_API ASceneRigPlayerManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigPlayerReference> Players;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USceneRigPlayer*> NewPlayersFromThisTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USceneRigPlayer*> ActivePlayersWantingToPlayThisTick;
    
    ASceneRigPlayerManager();
};


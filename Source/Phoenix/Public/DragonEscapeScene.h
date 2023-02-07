#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DragonEscapeScene.generated.h"

class USceneRig;
class USceneRigPlayer;
class USceneRigStageParameterBlock;

UCLASS(Blueprintable)
class ADragonEscapeScene : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USceneRigPlayer* m_SceneRigPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* m_DragonEscapeSceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigStageParameterBlock* ParameterBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AIDragon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* DragonPlatform;
    
    ADragonEscapeScene();
    UFUNCTION(BlueprintCallable)
    void QueueFinalRelease();
    
    UFUNCTION(BlueprintCallable)
    void PlaySceneRig();
    
    UFUNCTION(BlueprintCallable)
    void PlayQueuedFinalRelease();
    
};


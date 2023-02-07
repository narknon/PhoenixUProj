#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EConjurationSpawnState.h"
#include "ConjurationPreviewEffect.generated.h"

UCLASS(Blueprintable)
class AConjurationPreviewEffect : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnTimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* TargetPreviewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EConjurationSpawnState SpawnState;
    
public:
    AConjurationPreviewEffect();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateFXBlueprint(float DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndSpawnOutBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndSpawnInBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndSpawnedBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginSpawnOutBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginSpawnInBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginSpawnedBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeBlueprint();
    
    UFUNCTION(BlueprintCallable)
    float GetSpawnPercent();
    
};


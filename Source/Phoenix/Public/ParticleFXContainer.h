#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleFXContainer.generated.h"

class UNiagaraSystem;
class UParticleSystem;
class USceneComponent;

UCLASS(Blueprintable)
class AParticleFXContainer : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComp;
    
public:
    AParticleFXContainer();
    UFUNCTION(BlueprintCallable)
    void DestroySelf();
    
    UFUNCTION(BlueprintCallable)
    void DeactiveAndDestroyAfterXSeconds(float Seconds);
    
    UFUNCTION(BlueprintCallable)
    void AddParticleEmitter(UParticleSystem* SystemTemplate);
    
    UFUNCTION(BlueprintCallable)
    void AddNiagaraSystem(UNiagaraSystem* SystemTemplate);
    
};


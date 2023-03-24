#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraPoser.generated.h"

class UNiagaraPoserComponent;
class UNiagaraSystem;

UCLASS(Blueprintable)
class ANiagaraPoser : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraPoserComponent* PoserComponent;
    
    ANiagaraPoser(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetNiagaraSystem(UNiagaraSystem* NiagaraSystem, bool pAutoActivate);
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable)
    UNiagaraSystem* GetNiagaraSystem();
    
};


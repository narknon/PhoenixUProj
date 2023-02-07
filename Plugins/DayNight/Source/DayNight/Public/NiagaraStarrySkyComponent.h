#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NiagaraStarrySkyComponent.generated.h"

class UMaterialParameterCollection;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UNiagaraStarrySkyComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* StarrySkySystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroySystemWhenHidden;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* StarrySkyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* StarrySkyMPC;
    
public:
    UNiagaraStarrySkyComponent();
    UFUNCTION(BlueprintCallable)
    void SetSystem(UNiagaraSystem* NiagaraSystem);
    
    UFUNCTION(BlueprintCallable)
    void LoadSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoadedSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem) const;
    
};


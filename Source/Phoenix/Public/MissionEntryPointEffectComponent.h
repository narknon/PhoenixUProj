#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "MissionEntryPointEffectComponent.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMissionEntryPointEffectComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
public:
    UMissionEntryPointEffectComponent();
    UFUNCTION(BlueprintCallable)
    void Enable();
    
    UFUNCTION(BlueprintCallable)
    void Disable();
    
};


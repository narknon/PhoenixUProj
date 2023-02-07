#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "NiagaraMaterialDriverSetup.h"
#include "NiagaraMaterialDriverState.h"
#include "NiagaraMaterialDriverComponent.generated.h"

class UNiagaraComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SKINFX_API UNiagaraMaterialDriverComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraMaterialDriverSetup Setup;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FNiagaraMaterialDriverState State;
    
public:
    UNiagaraMaterialDriverComponent();
    UFUNCTION(BlueprintCallable)
    void Reset();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNiagaraSystemFinished(UNiagaraComponent* PSystem);
    
};


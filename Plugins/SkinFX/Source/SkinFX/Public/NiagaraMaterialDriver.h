#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NiagaraMaterialDriverSetup.h"
#include "NiagaraMaterialDriverState.h"
#include "NiagaraMaterialDriver.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class SKINFX_API UNiagaraMaterialDriver : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraMaterialDriverSetup Setup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FNiagaraMaterialDriverState State;
    
    UNiagaraMaterialDriver();
protected:
    UFUNCTION(BlueprintCallable)
    void OnNiagaraSystemFinished(UNiagaraComponent* PSystem);
    
};


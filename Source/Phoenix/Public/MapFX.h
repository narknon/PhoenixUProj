#pragma once
#include "CoreMinimal.h"
#include "MapFXBase.h"
#include "MapFX.generated.h"

class UNiagaraComponent;

UCLASS(Blueprintable)
class UMapFX : public UMapFXBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
public:
    UMapFX();
private:
    UFUNCTION(BlueprintCallable)
    void OnFinished(UNiagaraComponent* PSystem);
    
};


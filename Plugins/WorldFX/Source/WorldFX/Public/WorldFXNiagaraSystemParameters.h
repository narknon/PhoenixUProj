#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Interface_NiagaraHelpersInitializer.h"
#include "NiagaraHelpersInitializers.h"
#include "WorldFXNiagaraSystemParameters.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable)
class WORLDFX_API UWorldFXNiagaraSystemParameters : public UDataAsset, public IInterface_NiagaraHelpersInitializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> ReferenceNiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersInitializers Overrides;
    
    UWorldFXNiagaraSystemParameters();
    UFUNCTION(BlueprintCallable)
    void RefreshDefaults();
    
    UFUNCTION(BlueprintCallable)
    void DefaultsToParameters();
    
    UFUNCTION(BlueprintCallable)
    void ClearParameters();
    
    
    // Fix for true pure virtual functions not being implemented
};


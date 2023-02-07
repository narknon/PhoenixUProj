#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WorldFXAudioEventExtra.h"
#include "WorldFXComponentBase.h"
#include "WorldFXFull.h"
#include "WorldFXPresetComponent.generated.h"

class UAkAudioEvent;
class UWorldFXCascadeInstanceParametersBase;
class UWorldFXNiagaraSystemInitializer;
class UWorldFXRule;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WORLDFX_API UWorldFXPresetComponent : public UWorldFXComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* SFXEventOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideExtraEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldFXAudioEventExtra OverrideExtra;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXNiagaraSystemInitializer* NiagaraLocalInitializer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXCascadeInstanceParametersBase* CascadeLocalInstanceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorldFXRule* Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWorldFXFull WorldFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPresetSpawnAttached: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSpawnAttached: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_SpawnAttached: 1;
    
    UWorldFXPresetComponent();
    UFUNCTION(BlueprintCallable)
    void SetSpawnAttachedOverride(bool bNewSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ResetCascadeParameters();
    
    UFUNCTION(BlueprintCallable)
    void RefreshCascadeParameters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSpawnAttached(bool& bIsSpawnAttached);
    
    UFUNCTION(BlueprintCallable)
    void ClearSpawnAttachedOverride();
    
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Interface_NiagaraHelpersInitializer.h"
#include "NiagaraHelpersInitializers.h"
#include "NiagaraHelpersPrimFilter.h"
#include "NiagaraSystemSpawnAttachedInfo.h"
#include "NiagaraSystemSpawnAttachedPointInfo.h"
#include "NiagaraSystemSpawnInfo.h"
#include "NiagaraSystemSpawnMultiSkeletalInfo.h"
#include "NiagaraSystemSpawnMultiStaticInfo.h"
#include "NiagaraSystemWithVars.generated.h"

class AActor;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;
class USceneComponent;

UCLASS(Blueprintable)
class NIAGARAHELPERS_API UNiagaraSystemWithVars : public UDataAsset, public IInterface_NiagaraHelpersInitializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersInitializers Overrides;
    
    UNiagaraSystemWithVars();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void SpawnInWorldWithVars(UObject* WorldContextObject, FNiagaraSystemSpawnInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SpawnAttachedWithVars(USceneComponent* SceneComponent, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void SpawnAttachedActorWithVars(AActor* Actor, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) const;
    
    UFUNCTION(BlueprintCallable)
    void RefreshDefaults();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void MultiSpawnOnStaticMeshesWithVars(AActor* Actor, FNiagaraSystemSpawnMultiStaticInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void MultiSpawnOnSkeletalMeshesWithVars(AActor* Actor, FNiagaraSystemSpawnMultiSkeletalInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void MultiSpawnOnPrimitivesWithVars(AActor* Actor, FNiagaraSystemSpawnAttachedInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearOverrides();
    
    
    // Fix for true pure virtual functions not being implemented
};


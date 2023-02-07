#include "NiagaraSystemWithVars.h"

class AActor;
class UNiagaraComponent;
class UObject;
class USceneComponent;

void UNiagaraSystemWithVars::SpawnInWorldWithVars(UObject* WorldContextObject, FNiagaraSystemSpawnInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) const {
}

void UNiagaraSystemWithVars::SpawnAttachedWithVars(USceneComponent* SceneComponent, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) const {
}

void UNiagaraSystemWithVars::SpawnAttachedActorWithVars(AActor* Actor, FNiagaraSystemSpawnAttachedPointInfo SpawnInfo, UNiagaraComponent*& NiagaraComponent) const {
}

void UNiagaraSystemWithVars::RefreshDefaults() {
}

void UNiagaraSystemWithVars::MultiSpawnOnStaticMeshesWithVars(AActor* Actor, FNiagaraSystemSpawnMultiStaticInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) const {
}

void UNiagaraSystemWithVars::MultiSpawnOnSkeletalMeshesWithVars(AActor* Actor, FNiagaraSystemSpawnMultiSkeletalInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) const {
}

void UNiagaraSystemWithVars::MultiSpawnOnPrimitivesWithVars(AActor* Actor, FNiagaraSystemSpawnAttachedInfo SpawnInfo, FNiagaraHelpersPrimFilter Filter, TArray<UNiagaraComponent*>& NiagaraComponents) const {
}

void UNiagaraSystemWithVars::ClearOverrides() {
}

UNiagaraSystemWithVars::UNiagaraSystemWithVars() {
    this->NiagaraSystem = NULL;
}


#include "WorldFXSingleton.h"

class IWorldFXInterface;
class UWorldFXInterface;
class UActorComponent;
class UAkComponent;
class UNiagaraComponent;
class UObject;
class UParticleSystemComponent;
class UWorldFXRule;

bool AWorldFXSingleton::UnregisterWorldFXInterface(TScriptInterface<IWorldFXInterface> WorldFXInterface) {
    return false;
}

bool AWorldFXSingleton::RegisterWorldFXInterface(TScriptInterface<IWorldFXInterface> WorldFXInterface, FVector Position, FWorldFXSimpleCullDistance CullDistance, const UWorldFXRule* Rule, float ExtraRadius) {
    return false;
}

void AWorldFXSingleton::PresetRuleExists(FWorldFXPresetRuleName PresetName, bool& bResult) {
}

void AWorldFXSingleton::PresetRuleEvaluateWithSpawnParameters(UObject* WorldContextObject, FWorldFXPresetRuleName PresetName, FVector FXSpawnPosition, FWorldFXSpawnOverrides& SpawnOverrides, bool& bResult) {
}

void AWorldFXSingleton::PresetRuleEvaluate(UObject* WorldContextObject, FWorldFXPresetRuleName PresetName, FVector FXSpawnPosition, bool& bResult) {
}

void AWorldFXSingleton::IsWorldFXInterfaceRegistered(TScriptInterface<IWorldFXInterface> WorldFXInterface, bool& bIsRegistered) {
}

UWorldFXRule* AWorldFXSingleton::GetPresetRule(FWorldFXPresetRuleName PresetRuleName) {
    return NULL;
}

void AWorldFXSingleton::ForgetManagedNiagaraComponent(UNiagaraComponent* NiagaraComponent) {
}

void AWorldFXSingleton::ForgetManagedGenericComponent(UActorComponent* ActorComponent) {
}

void AWorldFXSingleton::ForgetManagedCascadeComponent(UParticleSystemComponent* ParticleSystemComponent) {
}

void AWorldFXSingleton::ForgetManagedAudioComponent(UAkComponent* AudioComponent) {
}

void AWorldFXSingleton::AutoManageNiagaraComponent(UNiagaraComponent* NiagaraComponent, float CullDistanceMeters) {
}

void AWorldFXSingleton::AutoManageGenericComponent(UActorComponent* ActorComponent, FWorldFXGenericManageSettings Manage, float CullDistanceMeters) {
}

void AWorldFXSingleton::AutoManageCascadeComponent(UParticleSystemComponent* ParticleSystemComponent, float CullDistanceMeters) {
}

void AWorldFXSingleton::AutoManageAudioComponent(UAkComponent* AudioComponent, float CullDistanceMeters) {
}

AWorldFXSingleton::AWorldFXSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCullingDisabled = false;
    this->AutoCascadeCullingLevel = 0;
    this->AutoNiagaraCullingLevel = 0;
    this->AutoAkAmbientCullingLevel = 0;
    this->FXOctreeFXDummy = NULL;
    this->bLastEyeValid = false;
}


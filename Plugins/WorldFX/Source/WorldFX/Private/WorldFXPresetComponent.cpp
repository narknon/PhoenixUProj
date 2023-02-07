#include "WorldFXPresetComponent.h"

void UWorldFXPresetComponent::SetSpawnAttachedOverride(bool bNewSpawnAttached) {
}

void UWorldFXPresetComponent::ResetCascadeParameters() {
}

void UWorldFXPresetComponent::RefreshCascadeParameters() {
}

void UWorldFXPresetComponent::GetSpawnAttached(bool& bIsSpawnAttached) {
}

void UWorldFXPresetComponent::ClearSpawnAttachedOverride() {
}

UWorldFXPresetComponent::UWorldFXPresetComponent() {
    this->SFXEventOverride = NULL;
    this->bOverrideExtraEnabled = false;
    this->NiagaraLocalInitializer = NULL;
    this->CascadeLocalInstanceParameters = NULL;
    this->Rule = NULL;
    this->bPresetSpawnAttached = false;
    this->bSpawnAttached = false;
    this->bOverride_SpawnAttached = false;
}


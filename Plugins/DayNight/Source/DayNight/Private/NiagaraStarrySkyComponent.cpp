#include "NiagaraStarrySkyComponent.h"

class UNiagaraSystem;

void UNiagaraStarrySkyComponent::SetSystem(UNiagaraSystem* NiagaraSystem) {
}

void UNiagaraStarrySkyComponent::LoadSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem) {
}

bool UNiagaraStarrySkyComponent::IsLoadedSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem) const {
    return false;
}

UNiagaraStarrySkyComponent::UNiagaraStarrySkyComponent() {
    this->StarrySkySystem = NULL;
    this->bDestroySystemWhenHidden = true;
    this->StarrySkyComponent = NULL;
}


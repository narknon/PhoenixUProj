#include "NiagaraPoserComponent.h"

class UNiagaraSystem;

void UNiagaraPoserComponent::Reset() {
}

void UNiagaraPoserComponent::CreateNiagaraSystem(UNiagaraSystem* NiagaraSystem, bool pAutoActivate) {
}

UNiagaraPoserComponent::UNiagaraPoserComponent() {
    this->MeshComponent = NULL;
    this->NiagaraComponent = NULL;
    this->Age = 0.00f;
    this->UpdateCounter = 0;
}


#include "NiagaraPoser.h"
#include "NiagaraPoserComponent.h"

class UNiagaraSystem;

void ANiagaraPoser::SetNiagaraSystem(UNiagaraSystem* NiagaraSystem, bool pAutoActivate) {
}

void ANiagaraPoser::Reset() {
}

UNiagaraSystem* ANiagaraPoser::GetNiagaraSystem() {
    return NULL;
}

ANiagaraPoser::ANiagaraPoser(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PoserComponent = CreateDefaultSubobject<UNiagaraPoserComponent>(TEXT("NiagaraPoser"));
}


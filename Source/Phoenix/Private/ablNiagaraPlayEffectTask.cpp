#include "ablNiagaraPlayEffectTask.h"

class UNiagaraComponent;

void UablNiagaraPlayEffectTask::DestroyNiagraEffects(UNiagaraComponent* InNiagaraComponent) {
}

UablNiagaraPlayEffectTask::UablNiagaraPlayEffectTask() {
    this->NiagaraVFX = NULL;
    this->bAttachToWand = false;
    this->bAttachToSocket = false;
    this->bDestroyAtTaskEnd = true;
    this->DestroyComponentDelay = 0.00f;
    this->bUseSpawnRateMultiply = false;
    this->SpawnRateMultiply = 0.00f;
}


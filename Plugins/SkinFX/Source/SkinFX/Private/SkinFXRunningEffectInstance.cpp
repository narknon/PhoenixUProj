#include "SkinFXRunningEffectInstance.h"

FSkinFXRunningEffectInstance::FSkinFXRunningEffectInstance() {
    this->NiagaraDriver = NULL;
    this->MaterialSwap = NULL;
    this->EventBroadcastMask = 0;
    this->EnvelopeState = ESkinFXEnvelopeState::Done;
    this->bEnvelopeStateValid = false;
    this->bHaveAppliedInitialParameters = false;
}


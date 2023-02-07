#include "MultiFX2_SkinFx.h"

UMultiFX2_SkinFx::UMultiFX2_SkinFx() {
    this->SkinFX = NULL;
    this->TimeScale = 1.00f;
    this->EndStyle = ESkinFXEffectEndStyle::Immediately;
    this->bUseEnvelopeOverride = false;
    this->bUseNiagaraOverride = false;
    this->bUseMeshStatesOverride = false;
}


#include "OverlapEffectsHandlerEffectNiagaraAttached.h"

UOverlapEffectsHandlerEffectNiagaraAttached::UOverlapEffectsHandlerEffectNiagaraAttached() {
    this->Attachment = EOverlapEffectsAttachment::Instigator;
    this->bOnlyOneEffectActiveAtAnyTime = true;
}


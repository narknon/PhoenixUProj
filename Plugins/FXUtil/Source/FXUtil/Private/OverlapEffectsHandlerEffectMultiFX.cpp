#include "OverlapEffectsHandlerEffectMultiFX.h"

UOverlapEffectsHandlerEffectMultiFX::UOverlapEffectsHandlerEffectMultiFX() {
    this->FXAsset = NULL;
    this->Attachment = EOverlapEffectsAttachment::Instigator;
    this->bOnlyOneEffectAtATime = true;
}


#include "SkinFXEnvelopeEase.h"

FSkinFXEnvelopeEase::FSkinFXEnvelopeEase() {
    this->Easing = EEasingFunc::Linear;
    this->BlendExp = 0.00f;
    this->Steps = 0;
}


#include "WindEnvelopeControllerASR.h"

UWindEnvelopeControllerASR::UWindEnvelopeControllerASR() {
    this->Delay = 0.00f;
    this->Attack = 0.00f;
    this->Sustain = 1.00f;
    this->Release = 0.33f;
    this->Amplitude = 1.00f;
    this->bLoop = false;
}


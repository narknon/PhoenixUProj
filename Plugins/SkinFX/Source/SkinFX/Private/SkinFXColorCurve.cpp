#include "SkinFXColorCurve.h"

FSkinFXColorCurve::FSkinFXColorCurve() {
    this->bStretchToEnvelope = false;
    this->bLoop = false;
    this->EnvelopeColorMod = ESkinFXEnvelopeColorMod::RGBONLY;
    this->bMultiplyByASREnvelope = false;
}


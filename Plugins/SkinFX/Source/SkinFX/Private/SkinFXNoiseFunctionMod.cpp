#include "SkinFXNoiseFunctionMod.h"

FSkinFXNoiseFunctionMod::FSkinFXNoiseFunctionMod() {
    this->TimeBase = 0.00f;
    this->Lumpiness = 0.00f;
    this->Amplitude = 0.00f;
    this->Offset = 0.00f;
    this->bStretchToEnvelope = false;
    this->bLoop = false;
    this->bMultiplyByASREnvelope = false;
}


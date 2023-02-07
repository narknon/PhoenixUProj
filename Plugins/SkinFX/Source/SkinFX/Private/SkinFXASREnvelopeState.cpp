#include "SkinFXASREnvelopeState.h"

FSkinFXASREnvelopeState::FSkinFXASREnvelopeState() {
    this->Age = 0.00f;
    this->StateTime = 0.00f;
    this->State = ESkinFXEnvelopeState::Done;
    this->CurveValue = 0.00f;
    this->LinearValue = 0.00f;
    this->bBreakHold = false;
}


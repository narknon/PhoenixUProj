#include "SkinFXASREnvelope.h"

FSkinFXASREnvelope::FSkinFXASREnvelope() {
    this->AttackDuration = 0.00f;
    this->SustainDuration = 0.00f;
    this->bSustainHold = false;
    this->ReleaseDuration = 0.00f;
    this->bInfiniteSustain = false;
    this->bInferLifetime = false;
}


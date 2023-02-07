#include "MultiFX2_WindVortexSource.h"

UMultiFX2_WindVortexSource::UMultiFX2_WindVortexSource() {
    this->Envelope = NULL;
    this->EnvelopeAffects = 1;
    this->Height = 500.00f;
    this->Radius = 150.00f;
    this->InnerRadius = 150.00f;
    this->Strength = 1.00f;
    this->Speed = 5.00f;
    this->WindGustController = NULL;
    this->OutdoorsOnly = 0.00f;
    this->Priority = 5000.00f;
    this->bAutoKillAfterEnvelope = true;
    this->bAttached = false;
    this->SourceCombine = EWindSourceCombine::Add;
}


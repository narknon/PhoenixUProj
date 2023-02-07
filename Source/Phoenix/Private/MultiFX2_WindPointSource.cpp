#include "MultiFX2_WindPointSource.h"

UMultiFX2_WindPointSource::UMultiFX2_WindPointSource() {
    this->Envelope = NULL;
    this->EnvelopeAffects = 4;
    this->Radius = 500.00f;
    this->InnerRadius = 500.00f;
    this->Strength = 1.00f;
    this->Speed = 10.00f;
    this->WindGustController = NULL;
    this->OutdoorsOnly = 0.00f;
    this->Priority = 5000.00f;
    this->bAutoKillAfterEnvelope = true;
    this->bAttached = false;
    this->SourceCombine = EWindSourceCombine::Add;
}


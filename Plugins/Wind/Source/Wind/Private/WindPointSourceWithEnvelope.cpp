#include "WindPointSourceWithEnvelope.h"
#include "WindPointSourceWithEnvelopeComponent.h"

AWindPointSourceWithEnvelope::AWindPointSourceWithEnvelope() {
    this->Component = CreateDefaultSubobject<UWindPointSourceWithEnvelopeComponent>(TEXT("WindPointSourceWithEnvelopeComponent0"));
}


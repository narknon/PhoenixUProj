#include "WindDirectionalSourceWithEnvelope.h"
#include "WindDirectionalSourceWithEnvelopeComponent.h"

AWindDirectionalSourceWithEnvelope::AWindDirectionalSourceWithEnvelope() {
    this->Component = CreateDefaultSubobject<UWindDirectionalSourceWithEnvelopeComponent>(TEXT("WindDirectionalSourceWithEnvelopeComponent0"));
}


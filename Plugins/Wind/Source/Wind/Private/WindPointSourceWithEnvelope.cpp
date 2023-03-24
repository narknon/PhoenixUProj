#include "WindPointSourceWithEnvelope.h"
#include "WindPointSourceWithEnvelopeComponent.h"

AWindPointSourceWithEnvelope::AWindPointSourceWithEnvelope(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindPointSourceWithEnvelopeComponent>(TEXT("WindPointSourceWithEnvelopeComponent0"));
}


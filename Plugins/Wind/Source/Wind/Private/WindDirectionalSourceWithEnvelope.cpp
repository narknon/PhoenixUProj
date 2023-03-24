#include "WindDirectionalSourceWithEnvelope.h"
#include "WindDirectionalSourceWithEnvelopeComponent.h"

AWindDirectionalSourceWithEnvelope::AWindDirectionalSourceWithEnvelope(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindDirectionalSourceWithEnvelopeComponent>(TEXT("WindDirectionalSourceWithEnvelopeComponent0"));
}


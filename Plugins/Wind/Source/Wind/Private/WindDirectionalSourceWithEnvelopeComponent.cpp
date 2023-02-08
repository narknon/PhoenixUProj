#include "WindDirectionalSourceWithEnvelopeComponent.h"

class UWindEnvelopeController;

/*void UWindDirectionalSourceWithEnvelopeComponent::SetEnvelopeAffects(EWindDirectionalEnvelopeAffects InNewEnvelopeAffects) {
}*/

void UWindDirectionalSourceWithEnvelopeComponent::SetEnvelope(const UWindEnvelopeController* InNewEnvelope) {
}

void UWindDirectionalSourceWithEnvelopeComponent::SetAutoKillAfterEnvelope(bool bInNewAutoKillAfterEnvelope) {
}

UWindDirectionalSourceWithEnvelopeComponent::UWindDirectionalSourceWithEnvelopeComponent() {
    this->Envelope = NULL;
    /*this->EnvelopeAffects = EWindDirectionalEnvelopeAffects::Speed;*/
    this->bAutoKillAfterEnvelope = false;
    this->StartTime = 0.00f;
    this->bActive = false;
}


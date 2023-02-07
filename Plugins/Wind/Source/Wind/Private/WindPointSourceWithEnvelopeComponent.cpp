#include "WindPointSourceWithEnvelopeComponent.h"

class UWindEnvelopeController;

void UWindPointSourceWithEnvelopeComponent::UnsetEnvelopeAffects(EWindPointEnvelopeAffects InNewEnvelopeAffects) {
}

void UWindPointSourceWithEnvelopeComponent::TestEnvelopeAffects(EWindPointEnvelopeAffects InNewEnvelopeAffects, bool& bIsSet) const {
}

void UWindPointSourceWithEnvelopeComponent::SetEnvelopeAffects(EWindPointEnvelopeAffects InNewEnvelopeAffects) {
}

void UWindPointSourceWithEnvelopeComponent::SetEnvelope(const UWindEnvelopeController* InNewEnvelope) {
}

void UWindPointSourceWithEnvelopeComponent::SetAutoKillAfterEnvelope(bool bInNewAutoKillAfterEnvelope) {
}

void UWindPointSourceWithEnvelopeComponent::ClearEnvelopeAffects() {
}

UWindPointSourceWithEnvelopeComponent::UWindPointSourceWithEnvelopeComponent() {
    this->Envelope = NULL;
    this->EnvelopeAffects = 1;
    this->bAutoKillAfterEnvelope = false;
    this->StartTime = 0.00f;
    this->bActive = false;
}


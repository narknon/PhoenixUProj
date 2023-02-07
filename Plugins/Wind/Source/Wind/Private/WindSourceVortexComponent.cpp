#include "WindSourceVortexComponent.h"

class UWindEnvelopeController;

void UWindSourceVortexComponent::UnsetEnvelopeAffects(EWindVortexEnvelopeAffects InNewEnvelopeAffects) {
}

void UWindSourceVortexComponent::TestEnvelopeAffects(EWindVortexEnvelopeAffects InNewEnvelopeAffects, bool& bIsSet) const {
}

void UWindSourceVortexComponent::SetStrength(float InNewStrength) {
}

void UWindSourceVortexComponent::SetSpeed(float InNewSpeed) {
}

void UWindSourceVortexComponent::SetRadius(float InNewRadius) {
}

void UWindSourceVortexComponent::SetInnerRadius(float InNewInnerRadius) {
}

void UWindSourceVortexComponent::SetHeight(float InNewHeight) {
}

void UWindSourceVortexComponent::SetEnvelopeAffects(EWindVortexEnvelopeAffects InNewEnvelopeAffects) {
}

void UWindSourceVortexComponent::SetEnvelope(const UWindEnvelopeController* InNewEnvelope) {
}

void UWindSourceVortexComponent::SetAutoKillAfterEnvelope(bool bInNewAutoKillAfterEnvelope) {
}

void UWindSourceVortexComponent::ClearEnvelopeAffects() {
}

UWindSourceVortexComponent::UWindSourceVortexComponent() {
    this->Height = 1000.00f;
    this->Radius = 250.00f;
    this->InnerRadius = 0.00f;
    this->Strength = 1.00f;
    this->Speed = 5.00f;
    this->Envelope = NULL;
    this->EnvelopeAffects = 1;
    this->bAutoKillAfterEnvelope = false;
    this->StartTime = 0.00f;
    this->bActive = false;
}


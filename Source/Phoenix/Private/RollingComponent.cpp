#include "RollingComponent.h"

class UPrimitiveComponent;

void URollingComponent::OnComponentWake(UPrimitiveComponent* OverlappedComponent, FName BoneName) {
}

void URollingComponent::OnComponentSleep(UPrimitiveComponent* OverlappedComponent, FName BoneName) {
}

URollingComponent::URollingComponent() {
    this->RollingAudioCutoffVelocity = 10.00f;
    this->AdditionalLineTraceDistance = 5.00f;
    this->VelocityLerpValue = 0.25f;
    this->InAirVelocityDecay = 0.90f;
    this->StaticMeshComp = NULL;
    this->AkComponent = NULL;
}


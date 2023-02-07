#include "TorchComponent.h"

class AActor;
class UPrimitiveComponent;

void UTorchComponent::StartLight() {
}

void UTorchComponent::SetOnFire(bool bOnFire) {
}


void UTorchComponent::Propagate() {
}

void UTorchComponent::OnProxOverlapBegin(AActor* OtherActor) {
}

void UTorchComponent::OnPropagateOverlapEnd(AActor* OtherActor) {
}

void UTorchComponent::OnPropagateOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor) {
}

void UTorchComponent::MidLight() {
}

void UTorchComponent::ExtinguishLight_Implementation() {
}


UTorchComponent::UTorchComponent() {
    this->bStartLit = true;
    this->bPropagate = true;
    this->bCastShadow = true;
    this->LightIntensity = 1500.00f;
    this->bCustomLightRadius = false;
    this->CustomLightRadius = 700.00f;
    this->bReceiveSequentialLighting = false;
    this->bSendSequentialLighting = false;
    this->SequentialLightSpreadRadius = 650.00f;
    this->bOverrideLightDelay = false;
    this->OverrideLightDelay = 0.20f;
    this->bIsLit = true;
    this->bLightTick = false;
    this->CurrentLightIntensity = 1500.00f;
    this->LightDelay = 0.20f;
    this->PropagateSphere = NULL;
    this->Ak_Fire_Burning_Loop = NULL;
    this->FirePointLight = NULL;
    this->AnimatedLight = NULL;
    this->TorchObjectState = NULL;
}


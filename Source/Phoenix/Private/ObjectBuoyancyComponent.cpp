#include "ObjectBuoyancyComponent.h"

void UObjectBuoyancyComponent::ToggleOn(bool bToggle) {
}

UObjectBuoyancyComponent::UObjectBuoyancyComponent() {
    this->Owner = NULL;
    this->TargetMesh = NULL;
    this->TargetMass = 0.00f;
    this->HoverHeight = 0.00f;
    this->TargetBuoyancy = 0.00f;
    this->ForcePercent = 0.00f;
    this->meshOrigin = 0.00f;
    this->meshExtent = 0.00f;
    this->bTicking = true;
}


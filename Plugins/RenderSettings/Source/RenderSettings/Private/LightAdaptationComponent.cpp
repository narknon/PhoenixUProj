#include "LightAdaptationComponent.h"

ULightAdaptationComponent::ULightAdaptationComponent() {
    this->Adaptation = -1.00f;
    this->LastExposure = -20.00f;
    this->FirstUpdateFrame = 0;
    this->bForceClusterUpdate = false;
}


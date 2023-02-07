#include "FillDecalPointLightComponent.h"

void UFillDecalPointLightComponent::SetRadii(float NewInnerCutoutRadius, float NewOuterCutoutRadius, float NewFullRadius) {
}

void UFillDecalPointLightComponent::SetOuterCutoutRadius(float NewOuterCutoutRadius) {
}

void UFillDecalPointLightComponent::SetIntensityMultiplier(float NewIntensityMultiplier) {
}

void UFillDecalPointLightComponent::SetInnerCutoutRadius(float NewInnerCutoutRadius) {
}

void UFillDecalPointLightComponent::SetFullRadius(float NewFullRadius) {
}

UFillDecalPointLightComponent::UFillDecalPointLightComponent() {
    this->IntensityMultiplier = 1.00f;
    this->InnerCutoutRadius = 0.00f;
    this->OuterCutoutRadius = 250.00f;
    this->FullRadius = 500.00f;
}


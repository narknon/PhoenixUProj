#include "FadeToDecalPointLightComponent.h"

void UFadeToDecalPointLightComponent::SetUseLightVisibility(bool bNewUseLightVisibility) {
}

void UFadeToDecalPointLightComponent::SetLightParametersCanChange(bool bNewLightParametersCanChange) {
}

UFadeToDecalPointLightComponent::UFadeToDecalPointLightComponent() {
    this->bUseLightVisibility = true;
    this->bLightParametersCanChange = false;
}


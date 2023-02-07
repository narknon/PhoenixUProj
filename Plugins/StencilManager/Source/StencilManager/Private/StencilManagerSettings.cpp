#include "StencilManagerSettings.h"

UStencilManagerSettings::UStencilManagerSettings() {
    this->PreferredStencilPostProcessingMaterial = NULL;
    this->bForcePreferredStencilPostProcessingMaterial = true;
    this->AccessibilityOverrides = NULL;
    this->WholeActorOverrides = NULL;
    this->LocalStencilFXOverrides = NULL;
}


#include "LocalStencilEffect.h"

FLocalStencilEffect::FLocalStencilEffect() {
    this->StencilValue = 0;
    this->OverrideClass = NULL;
    this->OverrideMaterial = NULL;
    this->FadeInTime = 0.00f;
    this->FadeOutTime = 0.00f;
    this->MeshScaleFactor = 0.00f;
    this->BoundsMethod = ELocalStencilBoundsMethod::Default;
    this->bRenderCustomDepth = false;
    this->bForcePlayerCustomDepth = false;
    this->bUseRotatingStencilValue = false;
}


#include "LocalStencilEffectActorOverrideParameters.h"

FLocalStencilEffectActorOverrideParameters::FLocalStencilEffectActorOverrideParameters() {
    this->OverrideClass = NULL;
    this->OverrideMaterial = NULL;
    this->FadeInTime = 0.00f;
    this->FadeOutTime = 0.00f;
    this->MeshScaleFactor = 0.00f;
    this->BoundsMethod = ELocalStencilBoundsMethod::Default;
    this->bForcePlayerCustomDepth = false;
    this->bOverride_FadeInTime = false;
    this->bOverride_FadeOutTime = false;
    this->bOverride_MeshScaleFactor = false;
    this->bOverride_TagFilter = false;
    this->bOverride_TypeFilter = false;
    this->bOverride_PrimitiveFilter = false;
    this->bOverride_PrimitiveClassFilter = false;
    this->bOverride_MeshInflateBounds = false;
    this->bOverride_BoundsMethod = false;
    this->bOverride_AttachComponentTag = false;
    this->bOverride_bForcePlayerCustomDepth = false;
}


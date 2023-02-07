#include "LocalStencilEffectDelegatedActorOverrideOverdraw.h"

ULocalStencilEffectDelegatedActorOverrideOverdraw::ULocalStencilEffectDelegatedActorOverrideOverdraw() {
    this->MeshScaleFactor = 1.00f;
    this->BoundsMethod = ELocalStencilBoundsMethod::Default;
    this->bOverride_MeshScaleFactor = false;
    this->bOverride_MeshInflateBounds = false;
    this->bOverride_BoundsMethod = false;
}


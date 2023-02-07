#include "LocalStencilEffectDelegatedActorOverrideRadiusAlpha.h"

ULocalStencilEffectDelegatedActorOverrideRadiusAlpha::ULocalStencilEffectDelegatedActorOverrideRadiusAlpha() {
    this->OutlineRadius = 1.00f;
    this->OutlineColorAlpha = 1.00f;
    this->OutlineColorAlphaPower = 3.00f;
    this->FinalIntensityMod = 4.00f;
    this->bSetOutlineRadius = false;
    this->bSetOutlineAlpha = false;
    this->bSetOutlineAlphaPower = false;
    this->bSetFinalIntensityMod = false;
}


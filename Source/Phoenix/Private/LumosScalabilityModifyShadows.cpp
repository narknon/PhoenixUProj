#include "LumosScalabilityModifyShadows.h"

ULumosScalabilityModifyShadows::ULumosScalabilityModifyShadows() {
    this->bProjectDynamicShadows = false;
    this->bCastVolumetricShadow = false;
    this->bCastTranslucentShadows = false;
    this->ContactShadows = ELumosContactShadows::None;
    this->ContactShadowLength = 100.00f;
    this->bOverride_bProjectDynamicShadows = false;
    this->bOverride_bCastVolumetricShadow = false;
    this->bOverride_bCastTranslucentShadows = false;
    this->bOverride_ContactShadows = false;
    this->bOverride_ContactShadowLength = false;
}


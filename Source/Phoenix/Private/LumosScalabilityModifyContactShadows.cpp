#include "LumosScalabilityModifyContactShadows.h"

ULumosScalabilityModifyContactShadows::ULumosScalabilityModifyContactShadows() {
    this->ContactShadows = ELumosContactShadows::None;
    this->ContactShadowLength = 100.00f;
    this->bOnlyIfContactShadowsEnabled = true;
}


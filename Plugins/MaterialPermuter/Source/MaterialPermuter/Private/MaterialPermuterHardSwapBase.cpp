#include "MaterialPermuterHardSwapBase.h"

FMaterialPermuterHardSwapBase::FMaterialPermuterHardSwapBase() {
    this->ParameterCopy = EMaterialPermuterParameterCopy::Default;
    this->bDisableMIDSharing = false;
}


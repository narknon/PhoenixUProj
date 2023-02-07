#include "MaterialSwapInfoOverrideMaterial.h"

FMaterialSwapInfoOverrideMaterial::FMaterialSwapInfoOverrideMaterial() {
    this->MaterialOverride = NULL;
    this->Priority = EMaterialSwapPriority::AlwaysInterrupt;
    this->ParameterCopy = EMaterialPermuterParameterCopy::Default;
}


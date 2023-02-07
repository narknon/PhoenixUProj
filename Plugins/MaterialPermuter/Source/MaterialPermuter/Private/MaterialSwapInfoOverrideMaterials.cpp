#include "MaterialSwapInfoOverrideMaterials.h"

FMaterialSwapInfoOverrideMaterials::FMaterialSwapInfoOverrideMaterials() {
    this->Priority = EMaterialSwapPriority::AlwaysInterrupt;
    this->ParameterCopy = EMaterialPermuterParameterCopy::Default;
}


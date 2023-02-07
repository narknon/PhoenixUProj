#include "MaterialSwapInfo.h"

FMaterialSwapInfo::FMaterialSwapInfo() {
    this->Priority = EMaterialSwapPriority::AlwaysInterrupt;
    this->SwapType = EMaterialSwapInfoTyoe::UseMaterialPermuter;
    this->MaterialOverride = NULL;
    this->ParameterCopy = EMaterialPermuterParameterCopy::Default;
}


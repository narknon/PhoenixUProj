#include "MaterialSwapKeyBundlePreload.h"

FMaterialSwapKeyBundlePreload::FMaterialSwapKeyBundlePreload() {
    this->Priority = EMaterialPermuterLoadingPriority::VeryLow;
    this->bAttachedChildren = false;
    this->bComponentChildren = false;
}


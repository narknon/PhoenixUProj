#include "MaterialPermuterLoadingBundleAndSwapOwner.h"

class AActor;
class UMaterialPermuterLoadingBundleAndSwapOwner;

UMaterialPermuterLoadingBundleAndSwapOwner* UMaterialPermuterLoadingBundleAndSwapOwner::CreateAndSwapOwner(AActor* Owner, FMaterialSwapKeyUI SwapInfo, FMaterialSwapParameters InitialParameters, EMaterialPermuterLoadingBundleAndSwapType MaterialSwapType, EMaterialPermuterLoadingPriority LoadPriority) {
    return NULL;
}

UMaterialPermuterLoadingBundleAndSwapOwner::UMaterialPermuterLoadingBundleAndSwapOwner() {
    this->SwapType = EMaterialPermuterLoadingBundleAndSwapType::SwapComponent;
}


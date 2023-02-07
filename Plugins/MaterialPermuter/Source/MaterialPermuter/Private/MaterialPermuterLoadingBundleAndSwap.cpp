#include "MaterialPermuterLoadingBundleAndSwap.h"

class UTexture;

void UMaterialPermuterLoadingBundleAndSwap::SetTextureParameter(FName Name, UTexture* Value) {
}

void UMaterialPermuterLoadingBundleAndSwap::SetScalarParameter(FName Name, float Value) {
}

void UMaterialPermuterLoadingBundleAndSwap::SetColorParameter(FName Name, FLinearColor Value) {
}

void UMaterialPermuterLoadingBundleAndSwap::ReleaseRawMaterialSwaps(bool bUnswap) {
}

void UMaterialPermuterLoadingBundleAndSwap::HasRawMaterialSwaps(int32& RawMaterialsSwapCount) const {
}

void UMaterialPermuterLoadingBundleAndSwap::GetMaterialSwapState(EMaterialPermuterLoadingBundleAndSwapState& CurrentSwapState) const {
}

void UMaterialPermuterLoadingBundleAndSwap::GetMaterialSwapKey(FMaterialPermuterKey& Key) const {
}

UMaterialPermuterLoadingBundleAndSwap::UMaterialPermuterLoadingBundleAndSwap() {
    this->MaterialSwapState = EMaterialPermuterLoadingBundleAndSwapState::Uninitialized;
}


#include "CustomizableWand.h"

class UTexture;

bool ACustomizableWand::AsyncLoadTexture(const TSoftObjectPtr<UTexture> SoftTexturePtr, const FName TexParam, const FAsyncWandTexLoadedCallback& Callback) {
    return false;
}

ACustomizableWand::ACustomizableWand() {
}


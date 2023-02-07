#include "MaterialSwap.h"

class UTexture;

void UMaterialSwap::SetVectorParameter(FName Name, FVector Value) {
}

void UMaterialSwap::SetVector4Parameter(FName Name, FVector4 Value) {
}

void UMaterialSwap::SetTextureParameter(FName Name, UTexture* Value) {
}

void UMaterialSwap::SetScalarParameter(FName Name, float Value) {
}

void UMaterialSwap::SetColorParameter(FName Name, FLinearColor Value) {
}

UMaterialSwap::UMaterialSwap() {
    this->Priority = EMaterialSwapPriority::AlwaysInterrupt;
}


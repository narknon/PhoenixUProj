#include "MaterialSwapComponent.h"

class AActor;
class UMaterialSwapComponent;
class UMeshComponent;
class UTexture;

bool UMaterialSwapComponent::ValidSwap() const {
    return false;
}

bool UMaterialSwapComponent::Swapped() const {
    return false;
}

void UMaterialSwapComponent::SetVectorParameter(FName Name, FVector Value) {
}

void UMaterialSwapComponent::SetVector4Parameter(FName Name, FVector4 Value) {
}

void UMaterialSwapComponent::SetTextureParameter(FName Name, UTexture* Value) {
}

void UMaterialSwapComponent::SetScalarParameter(FName Name, float Value) {
}

void UMaterialSwapComponent::SetParameters(const FMaterialSwapParameters& Params) {
}

void UMaterialSwapComponent::SetColorParameter(FName Name, FLinearColor Value) {
}

bool UMaterialSwapComponent::RestartSwap() {
    return false;
}

bool UMaterialSwapComponent::NewSwapAdvanced(const FMaterialSwapInfo& SwapInfo) {
    return false;
}

bool UMaterialSwapComponent::NewSwap(EMaterialSwapPriority Priority, FName Group, FName SubType) {
    return false;
}

void UMaterialSwapComponent::HasMaterialSwap(AActor* Actor, bool& bHasMaterialSwap) {
}

void UMaterialSwapComponent::GetMaterialSwap(AActor* Actor, UMaterialSwapComponent*& MaterialSwapComponent) {
}

FMaterialSwapComponentHandle UMaterialSwapComponent::GetCurrentHandle() const {
    return FMaterialSwapComponentHandle{};
}

void UMaterialSwapComponent::EndSwap(bool AllowRestart, bool ReleaseSwap) {
}

bool UMaterialSwapComponent::DestroySwapComponent(UMaterialSwapComponent* MaterialSwapComponent, bool bUnswap) {
    return false;
}

bool UMaterialSwapComponent::DestroySwap(AActor* Actor, bool unswap) {
    return false;
}

bool UMaterialSwapComponent::CreateSwapAdvanced(AActor* Actor, UMaterialSwapComponent*& MaterialSwapComponent, const FMaterialSwapInfo& SwapInfo, bool bAlwaysCreateNewComponent) {
    return false;
}

bool UMaterialSwapComponent::CreateSwap(AActor* Actor, UMaterialSwapComponent*& MaterialSwapComponent, EMaterialSwapPriority Priority, FName Group, FName SubType) {
    return false;
}

bool UMaterialSwapComponent::CreateMeshSwap(UMeshComponent* MeshComponent, UMaterialSwapComponent*& MaterialSwapComponent, const FMaterialSwapInfo& SwapInfo, bool bAlwaysCreateNewComponent) {
    return false;
}

UMaterialSwapComponent::UMaterialSwapComponent() {
    this->MaterialSwap = NULL;
}


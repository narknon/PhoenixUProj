#include "MaterialSwapSphereSelectionComponent.h"

class AActor;
class UTexture;

bool UMaterialSwapSphereSelectionComponent::Swapping() const {
    return false;
}

int32 UMaterialSwapSphereSelectionComponent::Swapped() const {
    return 0;
}

void UMaterialSwapSphereSelectionComponent::StartSwapping(const FMaterialSwapInfo& NewSwapInfo) {
}

void UMaterialSwapSphereSelectionComponent::SetVectorParameter(FName Name, FVector Value) {
}

void UMaterialSwapSphereSelectionComponent::SetVector4Parameter(FName Name, FVector4 Value) {
}

void UMaterialSwapSphereSelectionComponent::SetTextureParameter(FName Name, UTexture* Value) {
}

void UMaterialSwapSphereSelectionComponent::SetScalarParameter(FName Name, float Value) {
}

void UMaterialSwapSphereSelectionComponent::SetParameters(const FMaterialSwapParameters& Params) {
}

void UMaterialSwapSphereSelectionComponent::SetColorParameter(FName Name, FLinearColor Value) {
}

void UMaterialSwapSphereSelectionComponent::IsWeatherOnly(bool& OnlySwappingWeather) const {
}

bool UMaterialSwapSphereSelectionComponent::IsInside(AActor* Actor) const {
    return false;
}

void UMaterialSwapSphereSelectionComponent::GetCurrentSwapInfo(FMaterialSwapInfo& CurrentSwapInfo) const {
}

void UMaterialSwapSphereSelectionComponent::EndSwapping() {
}

UMaterialSwapSphereSelectionComponent::UMaterialSwapSphereSelectionComponent() {
    this->SphereType = EMaterialSwapSphereSelectionType::UseComponentLocation;
    this->SphereRadiusMeters = 8.00f;
    this->UnswapDelaySeconds = 1.00f;
    this->SwapSphereMaterialParameter = TEXT("MaterialSwapSphereXYZR");
    this->bSwapSphereMaterialParameter = false;
    this->bSwapOwner = false;
    this->bSwapping = false;
}


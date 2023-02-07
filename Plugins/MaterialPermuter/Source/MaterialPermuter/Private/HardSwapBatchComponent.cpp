#include "HardSwapBatchComponent.h"

class AActor;
class UTexture;

void UHardSwapBatchComponent::SetTextureParameter(FName Name, UTexture* Value) {
}

void UHardSwapBatchComponent::SetScalarParameter(FName Name, float Value) {
}

void UHardSwapBatchComponent::SetColorParameter(FName Name, FLinearColor Value) {
}

void UHardSwapBatchComponent::GetActorsToSwap(TArray<AActor*>& ActorsToSwapList) {
}

UHardSwapBatchComponent::UHardSwapBatchComponent() {
    this->Library = NULL;
    this->State = EHardSwapBatchComponentState::Startup;
}


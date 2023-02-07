#include "Loadingcreen.h"

class UTexture2D;

void ULoadingcreen::SetTextureByName(const FString& Name) {
}

void ULoadingcreen::SetTexture(UTexture2D* Texture) {
}

void ULoadingcreen::PickBackgroundID(const ELoadingScreenLocation DestinationLocation) {
}


void ULoadingcreen::GenerateTipList(const ELoadingScreenLocation DestinationLocation) {
}

void ULoadingcreen::DisplayPrevTip() {
}

void ULoadingcreen::DisplayNextTip() {
}

ULoadingcreen::ULoadingcreen() {
    this->LoadingImage = NULL;
}


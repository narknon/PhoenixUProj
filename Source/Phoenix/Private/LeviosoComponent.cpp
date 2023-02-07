#include "LeviosoComponent.h"

class AActor;

void ULeviosoComponent::SetIgnoreActors(TArray<AActor*> i_Ingores) {
}

void ULeviosoComponent::SetFloorHeight(float Height) {
}

void ULeviosoComponent::SetData(FLeviosoData InData) {
}

ULeviosoComponent::ULeviosoComponent() {
    this->ActiveMunition = NULL;
    this->SavedPhysMesh = NULL;
    this->SavedHoverTargetOffset = NULL;
    this->SavedHoverTargetRotation = NULL;
}


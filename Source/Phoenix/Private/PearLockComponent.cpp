#include "PearLockComponent.h"

void UPearLockComponent::ReplacePearDoorknob() {
}

void UPearLockComponent::DestroyPearMeshComponent() {
}

UPearLockComponent::UPearLockComponent() {
    this->PearMeshComponent = NULL;
    this->DoorknobMeshComponent = NULL;
    this->PearMesh = NULL;
    this->LaughingAnimation = NULL;
    this->DoorknobMesh = NULL;
    this->TickleTime = 3.00f;
    this->PearDoorknobTransformSystem = NULL;
    this->PearDoorknobComponent = NULL;
    this->Character = NULL;
}


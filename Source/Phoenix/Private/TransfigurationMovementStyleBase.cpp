#include "TransfigurationMovementStyleBase.h"

class AActor;

void ATransfigurationMovementStyleBase::UpdateFootprintRegionSizes(const FVector& PlacementFootprintSize) {
}

void ATransfigurationMovementStyleBase::StartTransition(float InDuration) {
}

void ATransfigurationMovementStyleBase::ShowDecal_Implementation(bool bShow) {
}

void ATransfigurationMovementStyleBase::ShowBeamAtLocalLocation_Implementation(const FVector& InLocationLocal) {
}

void ATransfigurationMovementStyleBase::SetWallTransformFromBounds_Implementation(const FVector& LocalExtent, const FVector& LocalLocation) {
}

void ATransfigurationMovementStyleBase::SetTransformFromBounds_Implementation(const FVector& LocalExtent, const FVector& LocalLocation) {
}

void ATransfigurationMovementStyleBase::SetPlacementRegionTransform() {
}

void ATransfigurationMovementStyleBase::Place_Implementation() {
}

void ATransfigurationMovementStyleBase::OnPreviewActorDestroyed(AActor* InActor) {
}

void ATransfigurationMovementStyleBase::Lift_Implementation() {
}

void ATransfigurationMovementStyleBase::ClearLitBeams_Implementation() {
}

void ATransfigurationMovementStyleBase::CanPlace_Implementation(bool bCanPlace) {
}

ATransfigurationMovementStyleBase::ATransfigurationMovementStyleBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PreviewActor = NULL;
    this->LinearInterpolationSpeed = 13.00f;
    this->bUseSpringDynamics = true;
    this->bDisperseNPCs = false;
}


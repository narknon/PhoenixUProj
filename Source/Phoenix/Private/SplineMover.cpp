#include "SplineMover.h"

void ASplineMover::DeactivateSplineMover_Implementation() {
}

void ASplineMover::ActivateSplineMover_Implementation() {
}

ASplineMover::ASplineMover() {
    this->bIsVisibleBeforeActive = false;
    this->Offset = 0.00f;
    this->MaxVelocity = 0.00f;
    this->InterpSpeed = 0.00f;
    this->Distance = 0.00f;
    this->Velocity = 0.00f;
    this->SplineComponent = NULL;
    this->CurrentSplinePointIndex = 0;
    this->HasPositionUpdated = false;
}


#include "OdcAuthoredObstacleSetupComponent.h"

UOdcAuthoredObstacleSetupComponent::UOdcAuthoredObstacleSetupComponent() {
    this->ShapeType = EOdcAuthoredObstacleShape::Prism;
    this->MinHeight = -10.00f;
    this->MaxHeight = 200.00f;
}


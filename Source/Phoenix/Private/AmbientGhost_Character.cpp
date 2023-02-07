#include "AmbientGhost_Character.h"





AAmbientGhost_Character::AAmbientGhost_Character() {
    this->SplineComponent = NULL;
    this->DistanceAlongSpline = 0.00f;
    this->TravelDirection = 1.00f;
    this->TravelSpeed = 150.00f;
    this->YawSpeed = 45.00f;
    this->TurnToFacePlayerSpeed = 90.00f;
    this->DistanceAtWhichGhostFacesPlayer = 1000.00f;
    this->VerticalDistanceAtWhichGhostFacesPlayer = 300.00f;
    this->OuterRadius = 2200.00f;
    this->OuterRadiusVerticalDistance = 1000.00f;
    this->InnerRadius = 400.00f;
    this->InnerRadiusVerticalDistance = 300.00f;
}


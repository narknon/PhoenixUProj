#include "RailTravelStatue.h"

class USplineComponent;

void ARailTravelStatue::InitializeForTravel(USplineComponent* InSplineComponent, float InTravelDirection) {
}

ARailTravelStatue::ARailTravelStatue(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SplineComponent = NULL;
    this->SpawnActorClass = NULL;
    this->StartSpeed = 450.00f;
    this->bUseActualSpeedAsStartSpeed = true;
    this->Acceleration = 200.00f;
    this->MinSpeed = 200.00f;
    this->MaxSpeed = 1000.00f;
    this->RotationSpeed = 720.00f;
    this->MaxOffsetRadius = 200.00f;
    this->SplineZOffset = 50.00f;
    this->SuckToSplineSpeed = 5.00f;
    this->YawSpeed = 90.00f;
    this->bDebug = false;
    this->TravelDirection = 1.00f;
}


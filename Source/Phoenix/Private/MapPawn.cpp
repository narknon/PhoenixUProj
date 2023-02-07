#include "MapPawn.h"
#include "Camera/CameraComponent.h"

AMapPawn::AMapPawn() {
    this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}


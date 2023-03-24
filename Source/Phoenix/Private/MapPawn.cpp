#include "MapPawn.h"
#include "Camera/CameraComponent.h"

AMapPawn::AMapPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}


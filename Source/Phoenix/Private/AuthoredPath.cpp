#include "AuthoredPath.h"
#include "Components/SplineComponent.h"

void AAuthoredPath::SnapPoints() {
}

void AAuthoredPath::ReversePoints() {
}

AAuthoredPath::AAuthoredPath() {
    this->PathComponent = CreateDefaultSubobject<USplineComponent>(TEXT("PathComponent"));
    this->SnapDistance = 200.00f;
}


#include "FlyingBook.h"

void AFlyingBook::Update(float DeltaTime) {
}

void AFlyingBook::RandomizeDistanceAlongSpline() {
}


AFlyingBook::AFlyingBook(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BookSpeed = 300.00f;
    this->BookSpeedMod = 1.00f;
    this->MainSplineReference = NULL;
    this->BookRoot = NULL;
    this->SplineLength = 0.00f;
    this->DistanceAlongSpline = 0.00f;
}


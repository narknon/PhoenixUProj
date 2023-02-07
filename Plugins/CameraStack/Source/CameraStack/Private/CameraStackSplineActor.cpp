#include "CameraStackSplineActor.h"
#include "Components/SplineComponent.h"

ACameraStackSplineActor::ACameraStackSplineActor() {
    this->SplineType = ECameraStackSplineType::LookAheadSpline;
    this->RailPairedSplineActor = NULL;
    this->bUseDifferentSplineWhenStartingAtEnd = false;
    this->RailPairedSplineActorStartingAtEnd = NULL;
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
}


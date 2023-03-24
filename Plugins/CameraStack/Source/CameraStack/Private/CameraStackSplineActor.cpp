#include "CameraStackSplineActor.h"
#include "Components/SplineComponent.h"

ACameraStackSplineActor::ACameraStackSplineActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SplineType = ECameraStackSplineType::LookAheadSpline;
    this->RailPairedSplineActor = NULL;
    this->bUseDifferentSplineWhenStartingAtEnd = false;
    this->RailPairedSplineActorStartingAtEnd = NULL;
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
}


#include "SlaveToSplineActor.h"
#include "Components/SplineComponent.h"

void ASlaveToSplineActor::ResetAll() {
}

ASlaveToSplineActor::ASlaveToSplineActor() {
    this->FollowSpline = CreateDefaultSubobject<USplineComponent>(TEXT("FollowSpline"));
}


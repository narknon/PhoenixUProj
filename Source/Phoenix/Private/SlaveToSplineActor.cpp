#include "SlaveToSplineActor.h"
#include "Components/SplineComponent.h"

void ASlaveToSplineActor::ResetAll() {
}

ASlaveToSplineActor::ASlaveToSplineActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FollowSpline = CreateDefaultSubobject<USplineComponent>(TEXT("FollowSpline"));
}


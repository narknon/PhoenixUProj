#include "UberExposureActor.h"
#include "UberExposureComponent.h"

AUberExposureActor::AUberExposureActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UUberExposureComponent>(TEXT("UberExposureComponent"));
}


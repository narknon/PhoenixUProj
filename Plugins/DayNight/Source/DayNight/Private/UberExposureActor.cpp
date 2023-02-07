#include "UberExposureActor.h"
#include "UberExposureComponent.h"

AUberExposureActor::AUberExposureActor() {
    this->Component = CreateDefaultSubobject<UUberExposureComponent>(TEXT("UberExposureComponent"));
}


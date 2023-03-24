#include "WindVortexSource.h"
#include "WindSourceVortexComponent.h"

AWindVortexSource::AWindVortexSource(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindSourceVortexComponent>(TEXT("WindSourceVortexComponent0"));
}


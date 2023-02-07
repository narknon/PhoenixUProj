#include "WindVortexSource.h"
#include "WindSourceVortexComponent.h"

AWindVortexSource::AWindVortexSource() {
    this->Component = CreateDefaultSubobject<UWindSourceVortexComponent>(TEXT("WindSourceVortexComponent0"));
}


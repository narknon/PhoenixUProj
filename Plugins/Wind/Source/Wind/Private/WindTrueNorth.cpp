#include "WindTrueNorth.h"
#include "WindTrueNorthComponent.h"

AWindTrueNorth::AWindTrueNorth() {
    this->Component = CreateDefaultSubobject<UWindTrueNorthComponent>(TEXT("WindTrueNorthComponent0"));
}


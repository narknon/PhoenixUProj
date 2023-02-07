#include "WindDeflector.h"
#include "WindDeflectorComponent.h"

AWindDeflector::AWindDeflector() {
    this->Component = CreateDefaultSubobject<UWindDeflectorComponent>(TEXT("WindDeflectorComponent0"));
}


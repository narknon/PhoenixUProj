#include "WindDeflector.h"
#include "WindDeflectorComponent.h"

AWindDeflector::AWindDeflector(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindDeflectorComponent>(TEXT("WindDeflectorComponent0"));
}


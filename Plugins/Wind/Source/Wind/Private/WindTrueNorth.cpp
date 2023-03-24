#include "WindTrueNorth.h"
#include "WindTrueNorthComponent.h"

AWindTrueNorth::AWindTrueNorth(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindTrueNorthComponent>(TEXT("WindTrueNorthComponent0"));
}


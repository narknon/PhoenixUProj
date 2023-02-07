#include "WindMapActor.h"
#include "WindMapComponent.h"

AWindMapActor::AWindMapActor() {
    this->Component = CreateDefaultSubobject<UWindMapComponent>(TEXT("WindMapComponent0"));
}


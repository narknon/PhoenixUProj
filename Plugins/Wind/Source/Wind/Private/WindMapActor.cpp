#include "WindMapActor.h"
#include "WindMapComponent.h"

AWindMapActor::AWindMapActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Component = CreateDefaultSubobject<UWindMapComponent>(TEXT("WindMapComponent0"));
}


#include "FluidSimActor.h"
#include "FluidSimComponent.h"
#include "FluidSimEmitterComponent.h"

AFluidSimActor::AFluidSimActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FluidSimComponent = CreateDefaultSubobject<UFluidSimComponent>(TEXT("FluidSimComponent0"));
    this->FluidSimEmitter = CreateDefaultSubobject<UFluidSimEmitterComponent>(TEXT("FluidSimEmitterComponent0"));
}


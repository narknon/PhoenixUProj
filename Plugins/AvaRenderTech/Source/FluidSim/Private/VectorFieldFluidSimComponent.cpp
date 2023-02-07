#include "VectorFieldFluidSimComponent.h"
#include "VectorFieldFluidSim.h"

UVectorFieldFluidSimComponent::UVectorFieldFluidSimComponent() {
    this->FluidSimVectorField = CreateDefaultSubobject<UVectorFieldFluidSim>(TEXT("FluidSimVectorField0"));
}


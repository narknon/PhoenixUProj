#include "VectorFieldFluidSimComponent.h"
#include "VectorFieldFluidSim.h"

UVectorFieldFluidSimComponent::UVectorFieldFluidSimComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->FluidSimVectorField = CreateDefaultSubobject<UVectorFieldFluidSim>(TEXT("FluidSimVectorField0"));
}

/*void UVectorFieldFluidSimComponent::SetIntensity(float NewIntensity)
{
    Intensity = NewIntensity;
}*/
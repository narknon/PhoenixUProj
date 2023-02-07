#pragma once
#include "CoreMinimal.h"
#include "Components/VectorFieldComponent.h"
#include "VectorFieldFluidSimComponent.generated.h"

class UVectorFieldFluidSim;

UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVectorFieldFluidSimComponent : public UVectorFieldComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVectorFieldFluidSim* FluidSimVectorField;
    
    UVectorFieldFluidSimComponent();
};


#pragma once
#include "CoreMinimal.h"
#include "VectorFieldFluidSim.h"
#include "Components/VectorFieldComponent.h"
#include "VectorFieldFluidSimComponent.generated.h"


UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVectorFieldFluidSimComponent : public UVectorFieldComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVectorFieldFluidSim* FluidSimVectorField;
    
    FLUIDSIM_API UVectorFieldFluidSimComponent(const FObjectInitializer& ObjectInitializer);
    
    /*virtual void SetIntensity(float NewIntensity) override;*/
};


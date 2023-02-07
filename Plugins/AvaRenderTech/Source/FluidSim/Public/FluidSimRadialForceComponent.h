#pragma once
#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "FluidSimRadialForceComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFluidSimRadialForceComponent : public USphereComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Force;
    
    UFluidSimRadialForceComponent();
    UFUNCTION(BlueprintCallable)
    void SetRadialForce(float ForceIn);
    
    UFUNCTION(BlueprintCallable)
    float GetRadialForce();
    
};


#pragma once
#include "CoreMinimal.h"
#include "VegetationInteractionSpringMassTracker.generated.h"

USTRUCT(BlueprintType)
struct FVegetationInteractionSpringMassTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpringMass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpringMassVelocity;
    
    PHOENIX_API FVegetationInteractionSpringMassTracker();
};


#pragma once
#include "CoreMinimal.h"
#include "TopographicDirection.h"
#include "EphemeralPlanetState.generated.h"

USTRUCT(BlueprintType)
struct FEphemeralPlanetState : public FTopographicDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunAngleDegrees;
    
    DAYNIGHT_API FEphemeralPlanetState();
};


#pragma once
#include "CoreMinimal.h"
#include "CelestialPointOfInterestName.generated.h"

USTRUCT(BlueprintType)
struct FCelestialPointOfInterestName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    DAYNIGHT_API FCelestialPointOfInterestName();
};


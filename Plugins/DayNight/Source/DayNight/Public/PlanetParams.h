#pragma once
#include "CoreMinimal.h"
#include "PlanetParams.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FPlanetParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* BaseMaterial;
    
    DAYNIGHT_API FPlanetParams();
};


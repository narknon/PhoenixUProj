#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsAdvancedParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsAdvancedParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogDensityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightFogDensityMultiplier;
    
    FVolumetricCloudsAdvancedParameters();
};


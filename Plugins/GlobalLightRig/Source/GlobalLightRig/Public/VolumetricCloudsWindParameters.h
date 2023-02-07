#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsWeatherWindParams.h"
#include "VolumetricCloudsWindParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsWindParameters : public FVolumetricCloudsWeatherWindParams {
    GENERATED_BODY()
public:
    FVolumetricCloudsWindParameters();
};


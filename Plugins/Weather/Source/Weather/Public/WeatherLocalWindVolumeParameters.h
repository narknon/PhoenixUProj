#pragma once
#include "CoreMinimal.h"
#include "WeatherLocalWindVolume.h"
#include "WindParameters.h"
#include "WeatherLocalWindVolumeParameters.generated.h"

UCLASS(Blueprintable)
class WEATHER_API ADEPRECATED_WeatherLocalWindVolumeParameters : public ADEPRECATED_WeatherLocalWindVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FWindParameters WindParameters;
    
    ADEPRECATED_WeatherLocalWindVolumeParameters();
};


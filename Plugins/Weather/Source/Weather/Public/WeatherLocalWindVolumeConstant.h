#pragma once
#include "CoreMinimal.h"
#include "WeatherLocalWindVolume.h"
#include "WindParametersInstant.h"
#include "WeatherLocalWindVolumeConstant.generated.h"

UCLASS(Blueprintable)
class WEATHER_API ADEPRECATED_WeatherLocalWindVolumeConstant : public ADEPRECATED_WeatherLocalWindVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FWindParametersInstant WindParameters;
    
    ADEPRECATED_WeatherLocalWindVolumeConstant();
};


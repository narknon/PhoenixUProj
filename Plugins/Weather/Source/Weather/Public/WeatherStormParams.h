#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfacePrecipitation.h"
#include "EWeatherSurfaceStormType.h"
#include "WeatherStormParams.generated.h"

USTRUCT(BlueprintType)
struct FWeatherStormParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfacePrecipitation Precipitation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceStormType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Coverage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StormHeight;
    
    WEATHER_API FWeatherStormParams();
};


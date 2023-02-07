#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeatherTimeBase.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherTimeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan RealElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan GameElapsedTime;
    
    FWeatherTimeBase();
};


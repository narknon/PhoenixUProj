#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfaceCharacterFXParameters.h"
#include "WeatherSurfaceCharacterFXParameter.generated.h"

USTRUCT(BlueprintType)
struct FWeatherSurfaceCharacterFXParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceCharacterFXParameters Red;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceCharacterFXParameters Green;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceCharacterFXParameters Blue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceCharacterFXParameters Alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetParameter;
    
    WEATHER_API FWeatherSurfaceCharacterFXParameter();
};


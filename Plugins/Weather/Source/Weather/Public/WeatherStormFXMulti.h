#pragma once
#include "CoreMinimal.h"
#include "WeatherStormFXBase.h"
#include "WeatherStormTypeFXSettings.h"
#include "WeatherStormTypeFXSettingsState.h"
#include "WeatherStormFXMulti.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherStormFXMulti : public AWeatherStormFXBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeatherStormTypeFXSettings> Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FWeatherStormTypeFXSettingsState> States;
    
    AWeatherStormFXMulti();
};


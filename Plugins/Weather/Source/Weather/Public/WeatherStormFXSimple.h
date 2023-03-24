#pragma once
#include "CoreMinimal.h"
#include "WeatherStormFXBase.h"
#include "WeatherStormTypeFXSettings.h"
#include "WeatherStormTypeFXSettingsState.h"
#include "WeatherStormFXSimple.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherStormFXSimple : public AWeatherStormFXBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherStormTypeFXSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeatherStormTypeFXSettingsState State;
    
    AWeatherStormFXSimple(const FObjectInitializer& ObjectInitializer);
};


#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalParameters.h"
#include "WeatherDecalSettings.h"
#include "WeatherDecalSettingsParameters.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalSettingsParameters : public UWeatherDecalSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDecalParameters Parameters;
    
    UWeatherDecalSettingsParameters();
};


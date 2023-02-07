#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomain.h"
#include "WeatherCustomBlendDomainWeatherCold.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainWeatherCold : public URenderSettingsCustomBlendDomain {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainWeatherCold();
};


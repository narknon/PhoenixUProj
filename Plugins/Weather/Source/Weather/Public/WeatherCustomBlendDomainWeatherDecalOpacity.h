#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "WeatherCustomBlendDomainWeatherDecalOpacity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainWeatherDecalOpacity : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainWeatherDecalOpacity();
};


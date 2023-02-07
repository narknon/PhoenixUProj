#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "WeatherCustomBlendDomainWeatherIndoorsBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainWeatherIndoorsBase : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainWeatherIndoorsBase();
};


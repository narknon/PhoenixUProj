#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "WeatherCustomBlendDomainWeatherIndoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainWeatherIndoors : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainWeatherIndoors();
};


#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "WeatherCustomBlendDomainWeatherOutdoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainWeatherOutdoors : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainWeatherOutdoors();
};


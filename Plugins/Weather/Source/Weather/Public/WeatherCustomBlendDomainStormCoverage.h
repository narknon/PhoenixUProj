#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "WeatherCustomBlendDomainStormCoverage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainStormCoverage : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainStormCoverage();
};


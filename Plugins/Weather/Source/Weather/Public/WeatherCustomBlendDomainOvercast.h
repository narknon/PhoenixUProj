#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "WeatherCustomBlendDomainOvercast.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainOvercast : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainOvercast();
};


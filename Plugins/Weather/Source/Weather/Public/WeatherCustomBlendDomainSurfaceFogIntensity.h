#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "WeatherCustomBlendDomainSurfaceFogIntensity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainSurfaceFogIntensity : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainSurfaceFogIntensity();
};


#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsNamedCustomBlendDomain.h"
#include "WeatherCustomBlendDomainWeatherCameraParticlesSpawnRate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainWeatherCameraParticlesSpawnRate : public URenderSettingsNamedCustomBlendDomain {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainWeatherCameraParticlesSpawnRate();
};


#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainBase.h"
#include "WeatherCustomBlendDomainBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherCustomBlendDomainBase : public URenderSettingsCustomBlendDomainBase {
    GENERATED_BODY()
public:
    UWeatherCustomBlendDomainBase();
};


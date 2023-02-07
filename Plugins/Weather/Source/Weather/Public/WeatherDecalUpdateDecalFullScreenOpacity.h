#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalUpdateSingleParameterFlex.h"
#include "WeatherDecalUpdateDecalFullScreenOpacity.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalUpdateDecalFullScreenOpacity : public UWeatherDecalUpdateSingleParameterFlex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeWeatherblendDomainOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bToggleVisibilityBasedOnOpacity;
    
    UWeatherDecalUpdateDecalFullScreenOpacity();
};


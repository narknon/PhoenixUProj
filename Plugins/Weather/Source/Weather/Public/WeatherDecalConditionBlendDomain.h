#pragma once
#include "CoreMinimal.h"
#include "BlendDomain.h"
#include "WeatherDecalSimpleCondition.h"
#include "WeatherDecalConditionBlendDomain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalConditionBlendDomain : public UWeatherDecalSimpleCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UWeatherDecalConditionBlendDomain();
};


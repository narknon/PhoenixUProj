#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalUpdate.h"
#include "WeatherDecalConditionalUpdate.generated.h"

class UWeatherDecalSettings;
class UWeatherDecalSimpleCondition;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalConditionalUpdate : public UWeatherDecalUpdate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSimpleCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> Settings;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeOverallBlend;
    
    UWeatherDecalConditionalUpdate();
};


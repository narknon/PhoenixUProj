#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalUpdate.h"
#include "WeatherDecalUpdateSingleParameter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalUpdateSingleParameter : public UWeatherDecalUpdate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UWeatherDecalUpdateSingleParameter();
};


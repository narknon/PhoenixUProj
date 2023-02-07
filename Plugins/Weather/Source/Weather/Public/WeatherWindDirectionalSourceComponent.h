#pragma once
#include "CoreMinimal.h"
#include "WeatherWindDirectionalSourceInstantComponent.h"
#include "WindParameters.h"
#include "WindParametersSampleTime.h"
#include "WeatherWindDirectionalSourceComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UWeatherWindDirectionalSourceComponent : public UWeatherWindDirectionalSourceInstantComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParameters WindParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParametersSampleTime SampleTime;
    
    UWeatherWindDirectionalSourceComponent();
};


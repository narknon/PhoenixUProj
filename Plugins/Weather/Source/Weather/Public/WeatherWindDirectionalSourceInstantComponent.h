#pragma once
#include "CoreMinimal.h"
#include "WeatherWindDirectionalSourceComponentBase.h"
#include "WindParametersInstant.h"
#include "Phoenix/Public/MultiFX2_WindDirectionalSource.h"
#include "WeatherWindDirectionalSourceInstantComponent.generated.h"


UCLASS(Blueprintable, CollapseCategories, EditInlineNew, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UWeatherWindDirectionalSourceInstantComponent : public UWeatherWindDirectionalSourceComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindParametersInstant WindParamsInstant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindGustController* WindGustController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Strength;
    
    UWeatherWindDirectionalSourceInstantComponent();
};


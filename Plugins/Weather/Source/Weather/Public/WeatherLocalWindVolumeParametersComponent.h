#pragma once
#include "CoreMinimal.h"
#include "WeatherLocalWindComponent.h"
#include "WindParameters.h"
#include "WeatherLocalWindVolumeParametersComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UDEPRECATED_WeatherLocalWindVolumeParametersComponent : public UDEPRECATED_WeatherLocalWindComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FWindParameters WindParameters;
    
    UDEPRECATED_WeatherLocalWindVolumeParametersComponent();
};


#pragma once
#include "CoreMinimal.h"
#include "WeatherLocalWindComponent.h"
#include "WindParametersInstant.h"
#include "WeatherLocalWindVolumeConstantComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UDEPRECATED_WeatherLocalWindVolumeConstantComponent : public UDEPRECATED_WeatherLocalWindComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FWindParametersInstant WindParameters;
    
    UDEPRECATED_WeatherLocalWindVolumeConstantComponent();
};


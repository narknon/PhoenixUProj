#pragma once
#include "CoreMinimal.h"
#include "WeatherVolume.h"
#include "WeatherVolumeSortable.generated.h"

UCLASS(Abstract, Blueprintable)
class WEATHER_API AWeatherVolumeSortable : public AWeatherVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    AWeatherVolumeSortable(const FObjectInitializer& ObjectInitializer);
};


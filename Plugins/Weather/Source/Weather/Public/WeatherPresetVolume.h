#pragma once
#include "CoreMinimal.h"
#include "WeatherDefinitionName.h"
#include "WeatherPresetVolumeBase.h"
#include "WeatherPresetVolume.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherPresetVolume : public AWeatherPresetVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDefinitionName Preset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seasons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInstantChange;
    
    AWeatherPresetVolume(const FObjectInitializer& ObjectInitializer);
};


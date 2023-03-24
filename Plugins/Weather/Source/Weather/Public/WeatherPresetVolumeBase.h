#pragma once
#include "CoreMinimal.h"
#include "WeatherVolumeSortablePreload.h"
#include "WeatherPresetVolumeBase.generated.h"

UCLASS(Blueprintable)
class WEATHER_API AWeatherPresetVolumeBase : public AWeatherVolumeSortablePreload {
    GENERATED_BODY()
public:
    AWeatherPresetVolumeBase(const FObjectInitializer& ObjectInitializer);
};


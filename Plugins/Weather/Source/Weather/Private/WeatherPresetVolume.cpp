#include "WeatherPresetVolume.h"

AWeatherPresetVolume::AWeatherPresetVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Seasons = 15;
    this->bInstantChange = false;
}


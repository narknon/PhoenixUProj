#include "WeatherSurfaceDataAsset.h"

UWeatherSurfaceDataAsset::UWeatherSurfaceDataAsset() {
    this->BPWeatherAnimationClass = NULL;
    this->BPWeatherCoverageClass = NULL;
    this->SwapRadius = 35.00f;
    this->bDoWeatherSwap = false;
}


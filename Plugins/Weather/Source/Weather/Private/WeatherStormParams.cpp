#include "WeatherStormParams.h"

FWeatherStormParams::FWeatherStormParams() {
    this->Precipitation = EWeatherSurfacePrecipitation::None;
    this->Type = EWeatherSurfaceStormType::None;
    this->Coverage = 0.00f;
    this->Intensity = 0.00f;
    this->StormHeight = 0.00f;
}


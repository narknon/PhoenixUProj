#include "VolumetricCloudsWeatherWindParams.h"

FVolumetricCloudsWeatherWindParams::FVolumetricCloudsWeatherWindParams() {
    this->UseWindSystemDirection = false;
    this->WindSpeedScale = 0.00f;
    this->WeatherSpeedScale = 0.00f;
    this->HighAltitudeSpeedScale = 0.00f;
    this->WindSkew = 0.00f;
    this->SkyLightWeatherSpeedScale = 0.00f;
}


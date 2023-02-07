#include "VolumetricCloudsWindParametersOverride.h"

FVolumetricCloudsWindParametersOverride::FVolumetricCloudsWindParametersOverride() {
    this->bOverride_WindSpeed = false;
    this->bOverride_WindSkew = false;
    this->bOverride_WeatherSpeed = false;
    this->bOverride_SkyLightWeatherSpeedScale = false;
    this->bOverride_HighAltitudeSpeed = false;
    this->WindSkew = 0.00f;
    this->SkyLightWeatherSpeedScale = 0.00f;
}


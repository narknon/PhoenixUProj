#include "SceneAction_WeatherSequenceStorm.h"

USceneAction_WeatherSequenceStorm::USceneAction_WeatherSequenceStorm() {
    this->PrecipitationType = EWeatherSurfacePrecipitation::Rain;
    this->Type = EWeatherSurfaceStormType::Normal;
    this->PreloadedPrecipitation = NULL;
}


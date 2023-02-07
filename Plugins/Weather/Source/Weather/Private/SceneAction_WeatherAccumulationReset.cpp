#include "SceneAction_WeatherAccumulationReset.h"

USceneAction_WeatherAccumulationReset::USceneAction_WeatherAccumulationReset() {
    this->PrecipitationPercentage = 0.00f;
    this->PrecipitationFadeTime = 1.50f;
    this->MaxWindSpeed = 12.00f;
    this->bSetMaxWindSpeed = true;
}


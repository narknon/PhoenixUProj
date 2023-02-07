#include "SceneAction_WeatherPreset.h"

USceneAction_WeatherPreset::USceneAction_WeatherPreset() {
    this->PlaybackScale = 1.00f;
    this->bInstantSwitch = true;
    this->bRestorePriorWeather = true;
    this->bRestorePriorWeatherInstant = true;
    this->bPreviewOnly = false;
}


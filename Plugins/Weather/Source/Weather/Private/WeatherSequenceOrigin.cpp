#include "WeatherSequenceOrigin.h"

FWeatherSequenceOrigin::FWeatherSequenceOrigin() {
    this->PlaybackScale = 0.00f;
    this->StackID = 0;
    this->Type = EWeatherSequenceOriginType::Default;
    this->PriorityBoost = 0;
    this->PlayingID = 0;
    this->bInstantChange = false;
    this->bRestorePriorWeather = false;
}


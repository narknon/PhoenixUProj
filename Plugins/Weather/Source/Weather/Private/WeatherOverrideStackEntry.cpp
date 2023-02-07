#include "WeatherOverrideStackEntry.h"

FWeatherOverrideStackEntry::FWeatherOverrideStackEntry() {
    this->PlaybackScale = 0.00f;
    this->bInstantSwitch = false;
    this->bRestorePriorWeather = false;
    this->bRestorePriorWeatherInstant = false;
    this->PriorityBoost = 0;
    this->UniqueId = 0;
}


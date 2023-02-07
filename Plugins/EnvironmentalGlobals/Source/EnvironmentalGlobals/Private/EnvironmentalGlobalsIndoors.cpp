#include "EnvironmentalGlobalsIndoors.h"

FEnvironmentalGlobalsIndoors::FEnvironmentalGlobalsIndoors() {
    this->GameIndoors = 0.00f;
    this->ProbeIndoors = 0.00f;
    this->WeatherIndoors = 0.00f;
    this->AudioIndoors = 0.00f;
    this->StreamingIndoors = 0.00f;
    this->bValidGameIndoors = false;
    this->bValidProbeIndoors = false;
    this->bValidWeatherIndoors = false;
    this->bValidAudioIndoors = false;
    this->bValidStreamingIndoors = false;
}


#include "WeatherLibrary.h"

UWeatherLibrary::UWeatherLibrary() {
    this->Sequences = NULL;
    this->FogDefinitions = NULL;
    this->CloudDefinitions = NULL;
    this->WindDefinitions = NULL;
    this->DefaultOvercastBlendable = NULL;
    this->ProhibitWeatherBlendDomain = NULL;
}


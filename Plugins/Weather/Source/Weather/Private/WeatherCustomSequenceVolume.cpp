#include "WeatherCustomSequenceVolume.h"

AWeatherCustomSequenceVolume::AWeatherCustomSequenceVolume(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseInFall = true;
    this->bUseInWinter = true;
    this->bUseInSpring = true;
    this->bUseInSummer = true;
}


#include "WeatherWindDirectionalSourceComponentBase.h"

UWeatherWindDirectionalSourceComponentBase::UWeatherWindDirectionalSourceComponentBase() {
    this->ExternalBlend = 1.00f;
    this->ForceBlendOut = 1.00f;
    this->OrphanDeathTime = 5.00f;
    this->OrphanDeathCountdown = 0.00f;
    this->bMarkedAsOrphan = false;
}


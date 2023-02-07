#include "WeatherStormFXBase.h"



void AWeatherStormFXBase::IsStorming(bool& bStorming) const {
}

void AWeatherStormFXBase::GetStormState(FWeatherStormState& StormState, bool& bStorming) const {
}

AWeatherStormFXBase::AWeatherStormFXBase() {
    this->WeatherStorm = NULL;
    this->OverrideActivationDistanceMeters = 100.00f;
    this->bUseOverrideActivationDistanceMeters = false;
}


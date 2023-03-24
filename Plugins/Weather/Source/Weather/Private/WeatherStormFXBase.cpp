#include "WeatherStormFXBase.h"



void AWeatherStormFXBase::IsStorming(bool& bStorming) const {
}

void AWeatherStormFXBase::GetStormState(FWeatherStormState& StormState, bool& bStorming) const {
}

AWeatherStormFXBase::AWeatherStormFXBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WeatherStorm = NULL;
    this->OverrideActivationDistanceMeters = 100.00f;
    this->bUseOverrideActivationDistanceMeters = false;
}


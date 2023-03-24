#include "WeatherVolumeSortable.h"

AWeatherVolumeSortable::AWeatherVolumeSortable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Priority = 0.00f;
    this->bUnbounded = false;
    this->bEnabled = true;
}


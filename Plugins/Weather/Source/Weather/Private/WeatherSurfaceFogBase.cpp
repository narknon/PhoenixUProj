#include "WeatherSurfaceFogBase.h"

void AWeatherSurfaceFogBase::RecalculateBounds() {
}



AWeatherSurfaceFogBase::AWeatherSurfaceFogBase() {
    this->SupportedFogTypes = 14;
    this->ShowingFogType = ESurfaceFogType::None;
}


#include "WeatherSurfaceFogBase.h"

void AWeatherSurfaceFogBase::RecalculateBounds() {
}



AWeatherSurfaceFogBase::AWeatherSurfaceFogBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SupportedFogTypes = 14;
    this->ShowingFogType = ESurfaceFogType::None;
}


#include "WeatherMaster.h"
#include "RenderSettingsComponent.h"
#include "WeatherMasterComponent.h"

void AWeatherMaster::NextSequence() {
}

AWeatherMaster::AWeatherMaster() {
    this->Component = CreateDefaultSubobject<UWeatherMasterComponent>(TEXT("WeatherMaster"));
    this->DebugWindComponent = NULL;
    this->OvercastVolume = CreateDefaultSubobject<URenderSettingsComponent>(TEXT("OvercastUnbounded"));
}


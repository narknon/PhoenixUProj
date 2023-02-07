#include "DayNightMaster.h"
#include "DayNightMasterComponent.h"

ADayNightMaster::ADayNightMaster() {
    this->DayNightMaster = CreateDefaultSubobject<UDayNightMasterComponent>(TEXT("DayNightMasterActor"));
    this->bAutoFindSkyActor = true;
}


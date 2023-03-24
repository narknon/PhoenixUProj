#include "DayNightMaster.h"
#include "DayNightMasterComponent.h"

ADayNightMaster::ADayNightMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DayNightMaster = CreateDefaultSubobject<UDayNightMasterComponent>(TEXT("DayNightMasterActor"));
    this->bAutoFindSkyActor = true;
}


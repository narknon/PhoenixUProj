#include "DayNightMasterComputeOnly.h"
#include "DayNightMasterComponent.h"

ADayNightMasterComputeOnly::ADayNightMasterComputeOnly() {
    this->DayNightMaster = CreateDefaultSubobject<UDayNightMasterComponent>(TEXT("DayNightMasterComputeOnly"));
}


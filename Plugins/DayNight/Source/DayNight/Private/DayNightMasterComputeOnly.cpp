#include "DayNightMasterComputeOnly.h"
#include "DayNightMasterComponent.h"

ADayNightMasterComputeOnly::ADayNightMasterComputeOnly(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DayNightMaster = CreateDefaultSubobject<UDayNightMasterComponent>(TEXT("DayNightMasterComputeOnly"));
}


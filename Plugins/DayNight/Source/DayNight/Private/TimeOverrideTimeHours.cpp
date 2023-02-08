#include "TimeOverrideTimeHours.h"

class UObject;
class UTimeOverrideTimeHours;

void UTimeOverrideTimeHours::TimeOverrideTimeHoursCreate(UObject* Owner, UTimeOverrideTimeHours*& TimeOverride, float CreateTime, ETimeOverrideType CreateType, float CreatePriority, bool bCreateEnabled, bool bIsTransient) {
}

UTimeOverrideTimeHours::UTimeOverrideTimeHours() {
    this->Time = 12.00f;
    this->Type = ETimeOverrideType::NormalizedTime;
    this->Priority = 0.00f;
    this->bEnabled = true;
}


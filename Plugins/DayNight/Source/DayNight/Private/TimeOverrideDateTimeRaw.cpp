#include "TimeOverrideDateTimeRaw.h"

class UObject;
class UTimeOverrideDateTimeRaw;

void UTimeOverrideDateTimeRaw::TimeOverrideDateTimeCreate(UObject* Owner, UTimeOverrideDateTimeRaw*& TimeOverride, FDateTime CreateDateTime, float CreatePriority, bool bCreateEnabled, bool bIsTransient) {
}

UTimeOverrideDateTimeRaw::UTimeOverrideDateTimeRaw() {
    this->Priority = 0.00f;
    this->bEnabled = true;
}


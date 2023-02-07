#include "GlobalLightGroupsImportSunScheduleEntry.h"

FGlobalLightGroupsImportSunScheduleEntry::FGlobalLightGroupsImportSunScheduleEntry() {
    this->OnAngle = EGlobalLightGroupsSunAngle::FullBrightSky;
    this->OnDirection = EGlobalLightGroupsSunDirection::Rise;
    this->OnAngleOffset = 0.00f;
    this->OnRandMinutesMin = 0.00f;
    this->OnRandMinutesMax = 0.00f;
    this->OffAngle = EGlobalLightGroupsSunAngle::FullBrightSky;
    this->OffDirection = EGlobalLightGroupsSunDirection::Rise;
    this->OffAngleOffset = 0.00f;
    this->OffRandMinutesMin = 0.00f;
    this->OffRandMinutesMax = 0.00f;
}


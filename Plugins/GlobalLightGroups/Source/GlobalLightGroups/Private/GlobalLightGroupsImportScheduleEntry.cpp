#include "GlobalLightGroupsImportScheduleEntry.h"

FGlobalLightGroupsImportScheduleEntry::FGlobalLightGroupsImportScheduleEntry() {
    this->OnHour = 0;
    this->OnMinute = 0;
    this->OnRandMinutesMin = 0.00f;
    this->OnRandMinutesMax = 0.00f;
    this->OffHour = 0;
    this->OffMinute = 0;
    this->OffRandMinutesMin = 0.00f;
    this->OffRandMinutesMax = 0.00f;
    this->bNormalizeForSeasons = false;
}


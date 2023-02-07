#include "DayNightWorldInfo.h"

FDayNightWorldInfo::FDayNightWorldInfo() {
    this->LevelDefaultBasis = NULL;
    this->ForceBasis = NULL;
    this->OverrideBasis = NULL;
    this->Master = NULL;
    this->bEventSystemReset = false;
    this->bMissingComputeMasterTemplate = false;
}


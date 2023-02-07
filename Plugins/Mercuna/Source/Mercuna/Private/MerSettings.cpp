#include "MerSettings.h"

UMerSettings::UMerSettings() {
    this->DebugLengthScale = 1000.00f;
    this->NumVoxelsPerSide = 32.00f;
    this->bAlwaysShowErrors = true;
    this->CellSize = 100.00f;
    this->MinPawnRadius = 1;
    this->MaxPawnRadius = 3;
    this->bAutoLinkNavVolumesWithOctrees = true;
    this->bAllowOctreeMerging = false;
    this->ModifierUsageTypes.AddDefaulted(1);
}


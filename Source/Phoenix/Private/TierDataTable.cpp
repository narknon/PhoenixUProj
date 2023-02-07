#include "TierDataTable.h"

FTierDataTable::FTierDataTable() {
    this->BeaconType = EBeaconType::BEACONTYPE_NONE;
    this->BeaconState = EBeaconState::BEACONSTATE_NONE;
    this->CanFastTravel = false;
    this->IconScale = 0.00f;
    this->IconZoomScaleFactor = 0.00f;
    this->IconPriority = 0;
}


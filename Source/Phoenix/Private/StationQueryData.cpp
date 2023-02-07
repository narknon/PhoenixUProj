#include "StationQueryData.h"

FStationQueryData::FStationQueryData() {
    this->ConnectionsBitmask = 0;
    this->StationValid = false;
    this->StationInteractionStatus = EStationInteraction::STATION_INTERACTION_CURRENT_NONE;
}


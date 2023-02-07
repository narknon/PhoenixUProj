#include "WorldEventDataRow.h"

FWorldEventDataRow::FWorldEventDataRow() {
    this->ProductionStatus = EProductionStatus::IN_DEVELOPMENT;
    this->NumberOfAllowedActiveInstances = 0;
    this->bPersistentEvent = false;
    this->bRepeatable = false;
    this->bCanSpawnAtLocationWithActivity = false;
    this->bOverrideLocatorCooldown = false;
    this->bIgnoreStreamoutVolume = false;
    this->bTestMinimumDistanceFromAnotherWorldEvent = false;
    this->MinimumDistanceFromAnotherWorldEvent = 0.00f;
    this->PercentChanceOfBeingSelected = 0;
    this->PreviewData = NULL;
}


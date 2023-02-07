#include "PlantDefinition.h"

FPlantDefinition::FPlantDefinition() {
    this->Tier = 0;
    this->GrowthTimeSec = 0;
    this->bIsMultiHarvestable = false;
    this->RegrowthTimeSec = 0;
    this->Yield_Planted = 0;
    this->Yield_Foraged = 0;
    this->SortingIndex = 0;
}


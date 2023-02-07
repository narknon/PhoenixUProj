#include "EncounterCreator.h"

AEncounterCreator::AEncounterCreator() {
    this->bActivateEncounter = true;
    this->bHideEncounterVolumes = false;
    this->DynamicObjectVolumeCount = 2;
    this->SpawnLocationCount = 5;
    this->EncounterVolume = NULL;
}


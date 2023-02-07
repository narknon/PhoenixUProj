#include "OverlapEffectsHandlerWindSpeedEntry.h"

FOverlapEffectsHandlerWindSpeedEntry::FOverlapEffectsHandlerWindSpeedEntry() {
    this->ClothingTypes = 0;
    this->Mode = EWindSpeedOverlapEffectsMode::IndoorsAndOutdoors;
    this->bStopProcessingWithClothingMatch = false;
    this->bUseStartEndSpeedMS = false;
    this->bUseMode = false;
    this->bHasStartedEffects = false;
}


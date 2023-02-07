#include "MultiFXPlus.h"

FMultiFXPlus::FMultiFXPlus() {
    this->PlacementMode = EMultiFXLoc::Location;
    this->MaxBoneFX = 0;
    this->DurationLimit = 0.00f;
    this->SecondsBetweenSpawns = 0.00f;
    this->bOnCharacters = false;
    this->bOnNonMovable = false;
    this->bOnNonActors = false;
    this->EndWhenMovementStops = false;
    this->RepeatMode = EMultiPlusRepeat::Standard;
}


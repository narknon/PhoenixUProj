#include "PerkTreeEntry.h"

FPerkTreeEntry::FPerkTreeEntry() {
    this->LevelRequirement = 0;
    this->Row = 0;
    this->Column = 0;
    this->State = EPerkState::PERK_UNAVAILABLE;
    this->CurrentLevel = 0;
    this->MaxLevel = 0;
    this->IsUpgrade = false;
    this->TotalEffectiveLevel = 0;
}


#include "RPGAbilityEventListener_OnCharacterDied.h"

URPGAbilityEventListener_OnCharacterDied::URPGAbilityEventListener_OnCharacterDied() {
    this->bKillInstigatorMustBeAbilityOwner = false;
    this->LevelComparison = ELevelComparison::None;
    this->LevelDifference = 0;
    this->MaximumDistance = -1.00f;
}


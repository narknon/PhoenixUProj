#include "CombatChallengeResultsBase.h"


void UCombatChallengeResultsBase::RestartFromDeath() {
}

void UCombatChallengeResultsBase::OnPostGameSave() {
}

void UCombatChallengeResultsBase::ExitRequested() {
}

UCombatChallengeResultsBase::UCombatChallengeResultsBase() {
    this->TitleText = TEXT("VICTORY");
    this->ResultIsAVictory = true;
}


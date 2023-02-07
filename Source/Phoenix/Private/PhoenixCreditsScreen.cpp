#include "PhoenixCreditsScreen.h"

void UPhoenixCreditsScreen::StartRollingCredits() {
}


UPhoenixCreditsScreen::UPhoenixCreditsScreen() {
    this->RollAnimationDuration = 10.00f;
    this->TimeBetweenEntries = 1.00f;
    this->CreditsCanvasPanel = NULL;
    this->DataTableLoaded = false;
    this->CreditsRolling = false;
    this->LastEntryReached = false;
    this->DurationMultiplier = 1.00f;
    this->CreditsEntryCounter = 0;
    this->TotalRollTime = 0.00f;
    this->TimeToNextEntry = 0.00f;
}


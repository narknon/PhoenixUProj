#include "FancyProgressBar.h"

void UFancyProgressBar::SetProgress(const float Progress) {
}

void UFancyProgressBar::SetGhostProgress(const float GhostProgress) {
}

void UFancyProgressBar::ResetProgress(const float Progress) {
}





UFancyProgressBar::UFancyProgressBar() {
    this->DelayBeforeDecay = 1.00f;
    this->DecayDuration = 1.00f;
    this->mProgress = 1.00f;
    this->mGhostProgress = 1.00f;
    this->mPreDecayProgress = 1.00f;
    this->mPreDecayGhostProgress = 1.00f;
    this->mInactiveDelayTimer = 0.00f;
    this->mDecayTimer = 0.00f;
}

